#include "win32_core.h"
#include "../internal.h"

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
		LOG_ERROR("WINDOW IS NULL");
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
		LOG_ERROR("COULDN'T FIND SPECIFIED PIXEL FORMAT");
		return FALSE;
	}

	SetPixelFormat(relib.win32.deviceContext, pixelFormat, &pfd);

	return TRUE;
}

DBool _win32_create_context(REWindow* window, REContextSettings* settings)
{
	REContext* context;
	win32Context* win32_context;

	if (!MALLOC(win32_context, 4))
		return FALSE;

	if (!MALLOC(context, 4))
	{
		FREE(win32_context);
		return FALSE;
	}

	if (!_choose_pixel_format(window, settings))
	{
		FREE(context);
		FREE(win32_context);
		LOG_ERROR("COULDN'T CHOOSE A PIXEL FORMAT");
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

DBool win32_make_context_current(REWindow* window)
{
	if (window)
	{
		HDC dc = GetDC(window->win32->windowHandle);
		if (!wglMakeCurrent(dc, window->context->win32->hglrc))
		{
			LOG_ERROR("COULDN'T MAKE THE CONTEXT CURRENT");
			return FALSE;
		}
	}
	else
	{
		LOG_ERROR("WINDOW IS NULL");
		if (!wglMakeCurrent(NULL, NULL))
		{
			LOG_ERROR("COULDN'T MAKE THE CONTEXT NULL");
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