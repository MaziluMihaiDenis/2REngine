#include "win32_core.h"
#include "../internal.h"
#include "../../DataTypes/dstring.h"
#include "../../DataTypes/dvector2d.h"

LRESULT CALLBACK _win32_win_procedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//REWindow* window = GetPropW(hwnd, L"RE");

	switch (msg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		//window->running = FALSE;
		break;
	case WM_CREATE:
		break;
	case WM_QUIT:
		PostQuitMessage(0);
		return;
	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

DBool win32_create_window(REWindow* window, REWindowSettings* windowSettings)
{
	const wchar_t* CLASS_NAME = L"RE2.0";
	const wchar_t* wideTitle;
	win32Window* win32_window;
	WNDCLASS wndClass = { 0 };

	if (!MALLOC(win32_window, 4))
		return FALSE;

	wndClass.lpfnWndProc = _win32_win_procedure;
	wndClass.hInstance = relib.win32.instance;
	wndClass.lpszClassName = CLASS_NAME;

	RegisterClass(&wndClass);

	wideTitle = char_to_wide(windowSettings->name);

	win32_window->windowHandle = CreateWindowExW(
		windowSettings->style,
		CLASS_NAME,
		wideTitle,
		WS_OVERLAPPEDWINDOW,
		windowSettings->pos.x, windowSettings->pos.y,
		windowSettings->size.x, windowSettings->size.y,
		(window->share ? window->share->win32->windowHandle : NULL),
		NULL,
		relib.win32.instance,
		NULL
	);

	if (win32_window->windowHandle == NULL)
		return FALSE;

	ShowWindow(win32_window->windowHandle, SW_SHOW);

	SetPropW(win32_window->windowHandle, L"RE", window);

	window->win32 = win32_window;

	return TRUE;
}

void win32_poll_events()
{
	if (!relib.mainWindow)
		return;

	MSG msg = { 0 };

	while (PeekMessageW(&msg, 0, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}

void win32_free_window(REWindow* window)
{
}