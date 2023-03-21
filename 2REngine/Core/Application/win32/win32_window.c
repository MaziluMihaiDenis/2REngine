#include "win32_core.h"
#include "../internal.h"
#include "../../Types/StringFunctions.h"
#include <stdio.h>
#include <WinUser.h>

unsigned char previousKeyState[256];

LRESULT CALLBACK _win32_win_procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void _win32_process_input(UINT Msg);

LRESULT CALLBACK _win32_win_procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	REWindow* window = (REWindow*)GetPropW(hwnd, L"RE");
	
	_win32_process_input(uMsg);

	if (window)
	{
		switch (uMsg)
		{
		case WM_CLOSE:
		case WM_DESTROY:
			window->running = FALSE;
			break;
		}
	}
	else
	{
		switch (uMsg)
		{
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
	{
		return FALSE;
	}

	if (windowSettings->visible)
	{
		ShowWindow(win32_window->windowHandle, SW_SHOW);
		SetPropW(win32_window->windowHandle, L"RE", window);
	}

	window->win32 = win32_window;

	return TRUE;
}

void _win32_process_input(UINT Msg)
{
	unsigned char keys[256];

	if (!GetKeyboardState(keys))
		return;

	for (int i = 48; i < 90; i++)
		if (Msg == WM_KEYDOWN && GetAsyncKeyState(i))
		{
			if (relib.callbacks.key != NULL)
			{
				if (GetAsyncKeyState(i) !=
					previousKeyState[i])
					relib.callbacks.key(i, 1);
				relib.callbacks.key(i, 2);
			}
		}
		else if(Msg == WM_KEYUP && previousKeyState[i] != keys[i])
		{
			if (relib.callbacks.key != NULL)
				relib.callbacks.key(i, 0);
		}


	for (int i = 48; i < 90; i++)
		previousKeyState[i] = GetAsyncKeyState(i);
}

void _win32_poll_events()
{
	if (!relib.windows[0])
		return;

	MSG msg = { 0 };

	while (PeekMessageW(&msg, 0, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}

void _win32_free_window(REWindow* window)
{
	FREE(window->win32);
}

