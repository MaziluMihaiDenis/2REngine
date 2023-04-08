#include "Application.h"
#include <2relibrary.h>

REWindow* Application::InstanceWindow(REWindowSettings* settings, const char* title, REWindow* share, bool fullscreen)
{
	REWindow* window;
	window = re_create_window(settings, title, fullscreen, share);
	return window;
}

REWindow* Application::GetWindowAt(int index)
{
	return re_get_window(index);
}

void Application::DestroyWindow(REWindow* window)
{
	re_destroy_context(window);
	re_free_window(window);
}

bool Application::IsRunning()
{
	return GetWindowInstance()->running;
}

void Application::Init()
{
	REWindowSettings* settings;
	int width, height;
	char* title = (char*)mem_alloc(256, NAME(title));

	char* save, * config;
	char s[] = "C:\\Users\\%USER%\\AppData\\Local";
	char c[] = "C:\\Users\\%USER%\\AppData\\Local\\mylifebelike\\Config\\engine.ini";

	save = get_env_path(s);
	config = get_env_path(c);
	sys_mkdir(save, "mylifebelike", save);

	// First start
	if (sys_mkdir(save, "Config", NULL) != -1)
	{
		re_get_monitor_size(&width, &height);
		sys_write_file(config, "%s%d", "window\\width = ", width);
		sys_write_file(config, "%s%d", "window\\height = ", height);
		sys_write_file(config, "%s%s", "window\\title = ", APPLICATION_TITLE);
	}

	{
		#undef SAVED_PATH
		#undef CONFIG_PATH
		#define SAVED_PATH save
		#define CONFIG_PATH config
	}

	width = sys_get_file_property_as_int(CONFIG_PATH, CONFIG_WINDOW_WIDTH);
	height = sys_get_file_property_as_int(CONFIG_PATH, CONFIG_WINDOW_HEIGHT);
	strcpy(title, sys_get_file_property_as_string(CONFIG_PATH, CONFIG_WINDOW_TITLE));

	if (!(settings = (REWindowSettings*)mem_alloc(sizeof(settings), NAME(settings))))
		return;

	settings->width = width;
	settings->height = height;
	settings->offsetY = 0;
	settings->offsetX = 0;
	settings->style = 0;
	settings->maximized = 0;
	settings->focused = 1;
	settings->visible = 1;
	settings->resizable = 1;

	re_set_context_current(InstanceWindow(settings, title, NULL, true));
}

void Application::PreLoop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(
		BackgroundColor.red,
		BackgroundColor.green,
		BackgroundColor.blue,
		BackgroundColor.alpha
	);

	re_poll_events();
}

void Application::Loop()
{
	re_swap_buffers(GetWindowInstance());
}

void Application::SetBackgroundColor(float red, float green, float blue, float alpha)
{
	BackgroundColor = { red, green, blue, alpha };
}

Application* Application::GetInstance()
{
	if (!Instance)
		Instance = new Application();
	return Instance;
}

REWindow* Application::GetWindowInstance()
{
	return re_get_main_window();
}
