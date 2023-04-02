#include "World.h"

World* World::GetInstance()
{
	if (!Instance)
		Instance = new World();
	return Instance;
}
