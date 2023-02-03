#include "win32_core.h"
#include "../internal.h"
#include "../../Types/StringFunctions.h"

LRESULT CALLBACK _win32_win_procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	REWindow* window = (REWindow*)GetPropW(hwnd, L"RE");
	
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

DBool win32_create_window(REWindow* window, REWindowSettings* windowSettings)
{
	if (!_win32_create_window_instance(window, windowSettings))
	{
		return FALSE;
	}
	if (!_win32_create_context(window, NULL))
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

	wideTitle = char_to_wchar_t(windowSettings->name);

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

	ShowWindow(win32_window->windowHandle, SW_SHOW);
	SetPropW(win32_window->windowHandle, L"RE", window);

	relib.win32.deviceContext = GetDC(win32_window->windowHandle);
	window->win32 = win32_window;

	return TRUE;
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