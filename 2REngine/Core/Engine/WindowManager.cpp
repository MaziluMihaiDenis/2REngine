#include "WindowManager.h"
#include "../../2relibrary.h"
#include "../../Constants.h"

void WindowManager::InitWindow()
{
	int width, height;
	char* title;

	width = sys_get_file_property_as_int(CONFIG_PATH, CONFIG_WINDOW_WIDTH);
	height = sys_get_file_property_as_int(CONFIG_PATH, CONFIG_WINDOW_HEIGHT);
	title = sys_get_file_property_as_string(CONFIG_PATH, CONFIG_WINDOW_TITLE);

	REWindowSettings settings
	{
		title,
		0, 0,
		width, height,
		0
	};

	AddWindow(&settings, NULL, FALSE);
}

REWindow* WindowManager::AddWindow(REWindowSettings* settings, REWindow* share, DBool fullscreen)
{
	REWindow* window;
	window = re_create_window(settings, fullscreen, share);

	return window;
}

bool WindowManager::CloseWindow(REWindow* window)
{
	return false;
}

REWindow* WindowManager::GetWindow(int index)
{
	return re_get_window(index);
}

WindowManager* WindowManager::GetInstance()
{
	if (!Instance)
		Instance = new WindowManager();
	return Instance;
}
