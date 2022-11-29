#include "win32_core.h"
#include "../internal.h"
#include "../../DataTypes/dstring.h"
#include "../../DataTypes/dvector2d.h"

LRESULT CALLBACK _win32_win_procedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	REWindow* window;
	if (window = GetProp(hwnd, L"RE2.0"))
	{
		switch (msg)
		{
		case WM_CREATE:
			break;
		case WM_CLOSE:
		case WM_DESTROY:
			window->running = FALSE;
			break;
		case WM_QUIT:
			PostQuitMessage(0);
			return;
		default:
			break;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

DBool win32_init()
{
	relib->win32->instance = GetModuleHandle(0);
	return TRUE;
}

win32Window* win32_create_window(REWindow* window, REWindowSettings* windowSettings)
{
	const wchar_t* CLASS_NAME = L"RE2.0";
	const wchar_t* wideTitle;
	win32Window* win32_window;
	WNDCLASS wndClass = { 0 };

	if (!MALLOC(win32_window, 4))
		return win32_create_window(window, windowSettings);

	wndClass.hInstance = relib->win32->instance;
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.lpfnWndProc = _win32_win_procedure;

	RegisterClass(&wndClass);

	wideTitle = char_to_wide(windowSettings->name);

	win32_window->windowHandle = CreateWindowEx(
		windowSettings->style,
		CLASS_NAME,
		wideTitle,
		WS_OVERLAPPEDWINDOW,
		windowSettings->size.x, windowSettings->size.y,
		windowSettings->pos.x, windowSettings->pos.y,
		(window->share ? window->share->win32->windowHandle : NULL),
		NULL,
		relib->win32->instance,
		NULL
	);

	free(wideTitle);

	if (win32_window->windowHandle == NULL)
	{
		free(win32_window);
		return win32_create_window(window, windowSettings);
	}

	ShowWindow(win32_window->windowHandle, SW_SHOW);

	SetProp(win32_window->windowHandle, L"RE2.0", window);

	return win32_window;
}