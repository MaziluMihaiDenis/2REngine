#include "WindowManager.h"
#include "../2relibrary.h"
#include "../File Worker/FileWorker.h"

void WindowManager::InitWindow()
{
	int width, height;
	height = get_property_value_as_int("C:\\Users\\mazil\\AppData\\Roaming\\2REngine\\config.cfg",
		"engine\\runtime\\window\\height");
	width = get_property_value_as_int("C:\\Users\\mazil\\AppData\\Roaming\\2REngine\\config.cfg",
		"engine\\runtime\\window\\width");

	REWindowSettings settings
	{
		MAKE_STR("NIGGA BALLS"),
		MAKE_VEC(600, 540),
		MAKE_VEC(width, height),
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

WindowManager* WindowManager::GetWindowManager()
{
	if (!WindowManagerInstance)
		WindowManagerInstance = new WindowManager();
	return WindowManagerInstance;
}
