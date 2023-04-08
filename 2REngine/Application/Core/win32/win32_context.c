#include "win32_core.h"
#include "../internal.h"
#include <External/Glad/glad_wgl.h>
#include <Debug/debug.h>

DBool _wgl_choose_pixel_format(REWindow* window)
{
	int attribList[] = {
		WGL_DRAW_TO_WINDOW_ARB, TRUE,
		WGL_SUPPORT_OPENGL_ARB, TRUE,
		WGL_DOUBLE_BUFFER_ARB, TRUE,
		WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		WGL_COLOR_BITS_ARB, 32,
		WGL_DEPTH_BITS_ARB, 24,
		WGL_STENCIL_BITS_ARB, 8,
		0
	};

	int pixelFormat = 0;
	UINT numFormats = 0;
	PIXELFORMATDESCRIPTOR pfd = {0};
	HDC dc = GetDC(window->win32->windowHandle);

	wglChoosePixelFormatARB(dc, attribList, NULL, 1, &pixelFormat, &numFormats);

	DescribePixelFormat(dc, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	SetPixelFormat(dc, pixelFormat, &pfd);

	return TRUE;
}

DBool _choose_pixel_format(REWindow* window)
{
	if (!window)
	{
		return FALSE;
	}

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,
		8,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	HDC dc = GetDC(window->win32->windowHandle);
	int pixelFormat = ChoosePixelFormat(dc, &pfd);

	if (!pixelFormat)
	{
		return FALSE;
	}

	SetPixelFormat(dc, pixelFormat, &pfd);

	return TRUE;
}

DBool _win32_create_context(REWindow* window, REContextSettings* settings)
{
	REContext* context;
	win32Context* win32_context;
	HDC dc = GetDC(window->win32->windowHandle);

	if (!MALLOC(win32_context, sizeof(win32Context)))
		return FALSE;

	if (!MALLOC(context, sizeof(REContext)))
	{
		FREE(win32_context);
		return FALSE;
	}

	if (settings)
	{
		int openGLAttributes[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, settings->major,
			WGL_CONTEXT_MINOR_VERSION_ARB, settings->minor,
			WGL_CONTEXT_PROFILE_MASK_ARB, settings->profile,
			settings->forward
		};

		_wgl_choose_pixel_format(window);
		win32_context->hglrc = wglCreateContextAttribsARB(dc, 0, openGLAttributes); // NULL
	}
	else
	{
		_choose_pixel_format(window, settings);
		win32_context->hglrc = wglCreateContext(dc);
	}
	context->win32 = win32_context;
	window->context = context;

	return TRUE;
}

DBool _win32_set_context_current(REWindow* window)
{
	if (window)
	{
		HDC dc = GetDC(window->win32->windowHandle);
		relib.win32.deviceContext = dc;
		if (!wglMakeCurrent(dc, window->context->win32->hglrc))
			return FALSE;
		return TRUE;
	}
	wglMakeCurrent(NULL, NULL);
	return TRUE;
}

DBool _win32_init_gl()
{
	REWindow* window;
	REWindowSettings wind_settings = { 0 };

	if (!MALLOC(window, sizeof(REWindow)))
		return FALSE;

	window->name = L"?";

	_win32_create_window(window, &wind_settings, NULL);
	_win32_set_context_current(window);

	if (!gladLoadWGL(GetDC(window->win32->windowHandle)))
		return FALSE;

	if (!gladLoadGL())
		return FALSE;

	re_destroy_context(window);
	FREE(window->win32);
	FREE(window);

	return TRUE;
}

void _win32_destroy_context(struct REWindow* window)
{
	_win32_set_context_current(NULL);
	wglDeleteContext(window->context->win32->hglrc);
	FREE(window->context->win32);
}

void _win32_swap_buffers(REWindow* window)
{
	SwapBuffers(relib.win32.deviceContext);
}