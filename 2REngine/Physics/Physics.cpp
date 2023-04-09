#include "Physics.h"

void Physics::Init()
{

}

void Physics::Loop()
{

}

void Physics::HandleRRCollision()
{
}

void Physics::HandleRCCollision()
{
}

void Physics::HandleCCCollision()
{
}
	
void Physics::RegisterCollider(CollisionShape2D* collider)
{
	RegisteredColliders.push_back(collider);
}

void Physics::UnregisterCollider(CollisionShape2D* collider)
{
	for(int i = 0; i < RegisteredColliders.size(); i++)
		if(collider == RegisteredColliders[i])
			RegisteredColliders.erase(RegisteredColliders.begin() + i);
}

Physics* Physics::GetInstance()
{
	if (!Instance)
		Instance = new Physics();
	return Instance;
}
