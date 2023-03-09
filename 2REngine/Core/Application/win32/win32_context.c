#include "win32_core.h"
#include "../internal.h"

// TODO: use gl extensions for pixel format

DBool _choose_pixel_format(REWindow* window, REContextSettings* settings)
{
	if (!_wgl_choose_pixel_format(window, settings))
		if (!_win32_choose_pixel_format(window, settings))
			return FALSE;

	return TRUE;
}

DBool _wgl_choose_pixel_format(REWindow* window, REContextSettings* settings)
{
	return FALSE;
}

DBool _win32_choose_pixel_format(REWindow* window, REContextSettings* settings)
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

	SetPixelFormat(relib.win32.deviceContext, pixelFormat, &pfd);

	return TRUE;
}

DBool _win32_create_context(REWindow* window, REContextSettings* settings)
{
	REContext* context;
	win32Context* win32_context;

	if (!MALLOC(win32_context, sizeof(win32Context)))
		return FALSE;

	if (!MALLOC(context, sizeof(REContext)))
	{
		FREE(win32_context);
		return FALSE;
	}

	if (!_choose_pixel_format(window, settings))
	{
		FREE(context);
		FREE(win32_context);
		return FALSE;
	}

	if (!(win32_context->hglrc = wglCreateContext(relib.win32.deviceContext)))
	{
		FREE(context);
		FREE(win32_context);
		return FALSE;	
	}

	context->win32 = win32_context;
	if(window)
		window->context = context;

	return TRUE;
}

DBool _win32_set_context_current(REWindow* window)
{
	if (window)
	{
		HDC dc = GetDC(window->win32->windowHandle);
		if (!wglMakeCurrent(dc, window->context->win32->hglrc))
		{
			return FALSE;
		}
	}
	else
	{
		if (!wglMakeCurrent(NULL, NULL))
		{
			return FALSE;
		}
	}
	return TRUE;
}

DBool _win32_init_gl()
{
	//if (!_win32_create_context(0, 0))
	//	LOG_ERROR("COULDN'T CREATE A FALSE CONTEXT");
	return TRUE;
}

void _win32_swap_buffers(REWindow* window)
{
	SwapBuffers(GetDC(window->win32->windowHandle));
}