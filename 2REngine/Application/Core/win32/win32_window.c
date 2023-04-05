#include "win32_core.h"
#include "../internal.h"
#include <Basic/string_functions.h>
#include <stdio.h>
#include <WinUser.h>

LRESULT CALLBACK _win32_win_procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK _win32_win_procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	REWindow* window = (REWindow*)GetPropW(hwnd, L"RE2.0");

	if (window)
	{
		switch (uMsg)
		{
		case WM_KEYUP:
		case WM_KEYDOWN:
			_win32_process_input(uMsg);
			break;
		case WM_CLOSE:
			PostQuitMessage(0);
			window->running = FALSE;
			DestroyWindow(window->win32->windowHandle);
			break;
		}
	}
	else
	{
		switch (uMsg)
		{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

DBool _win32_create_window(struct REWindow* window, struct REWindowSettings* winSet, struct REContextSettings* ctxSet)
{
	if (!_win32_create_window_instance(window, winSet))
	{
		return FALSE;
	}
	if (!_win32_create_context(window, ctxSet))
	{
		FREE(window->win32);
		return FALSE;
	}
	return TRUE;
}

DBool _win32_create_window_instance(REWindow* window, REWindowSettings* windowSettings)
{
	const wchar_t* CLASS_NAME = L"RE2.0";
	wchar_t* wideTitle;
	win32Window* win32_window;
	WNDCLASS wndClass = { 0 };

	if (!MALLOC(win32_window, sizeof(win32Window)))
		return FALSE;

	wndClass.lpfnWndProc = _win32_win_procedure;
	wndClass.hInstance = relib.win32.instance;
	wndClass.lpszClassName = CLASS_NAME;

	RegisterClass(&wndClass);

	wideTitle = char_to_wchar_t(window->name);

	win32_window->windowHandle = CreateWindowEx(
		windowSettings->style,
		CLASS_NAME,
		wideTitle,
		WS_OVERLAPPEDWINDOW,
		windowSettings->offsetX, windowSettings->offsetY,
		windowSettings->width, windowSettings->height,
		NULL,
		NULL,
		relib.win32.instance,
		NULL
	);

	if (win32_window->windowHandle == NULL)
		return FALSE;

	if(windowSettings->focused)
		SetPropW(win32_window->windowHandle, L"RE2.0", window);

	if (windowSettings->visible)
		ShowWindow(win32_window->windowHandle, SW_SHOW);

	window->win32 = win32_window;

	return TRUE;
}

void _win32_poll_events()
{
	if (!relib.main_window)
		return;

	MSG msg = { 0 };

	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void _win32_free_window(REWindow* window)
{
	FREE(window->win32);
}

