#include "Engine.h"
#include "WindowManager.h"
#include "../../2relibrary.h"
#include "../../Paths.h"

void Engine::FirstStart()
{
	sys_mkdir("C:\\Users\\mazil\\Documents\\mylifebelike", "Config");
	sys_write_file(CONFIG_PATH, "%s%d", "window\\width = ", 800);
	sys_write_file(CONFIG_PATH, "%s%d", "window\\height = ", 600);
	sys_write_file(CONFIG_PATH, "%s%s", "window\\title = ", "MyLifeBeLike");
}

void Engine::Begin()
{
	if (sys_mkdir("C:\\Users\\mazil\\Documents\\", "mylifebelike"))
		FirstStart();
	WindowManager::GetInstance()->InitWindow();
}

void Engine::Loop()
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
