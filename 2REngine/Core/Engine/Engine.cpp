#include "Engine.h"
#include "WindowManager.h"
#include "../../2relibrary.h"
#include "../../Constants.h"
#include "Classes/EmptyWorldObject.h"

void Engine::FirstStart()
{
	int width, height;

	re_get_monitor_size(&width, &height);

	sys_mkdir("C:\\Users\\mazil\\Documents\\mylifebelike", "Config");
	sys_write_file(CONFIG_PATH, "%s%d", "window\\width = ", width);
	sys_write_file(CONFIG_PATH, "%s%d", "window\\height = ", height);
	sys_write_file(CONFIG_PATH, "%s%s", "window\\title = ", APPLICATION_TITLE);
}

void Engine::Begin()
{
	if (sys_mkdir("C:\\Users\\mazil\\Documents", "mylifebelike") == 1)
		FirstStart();
	WindowManager::GetInstance()->InitWindow();

	EmptyWorldObject* obj = new EmptyWorldObject();
	obj->AddComponent<Component>();
	obj->GetComponent<Component>();
}

void Engine::Loop(float deltaTime)
{
}

void Engine::End()
{
}

Engine* Engine::GetInstance()
{
	if (!Instance)
		Instance = new Engine();
	return Instance;
}
