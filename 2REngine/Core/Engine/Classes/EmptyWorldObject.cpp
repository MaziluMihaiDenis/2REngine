#include "EmptyWorldObject.h"

void EmptyWorldObject::Loop(float deltaTime)
{
	for (Object*& child : Children)
		child->Loop(deltaTime);
	for (Component*& component : Components)
		component->Loop(deltaTime);
}

void EmptyWorldObject::RemoveComponent(Component* component)
{
	for (std::vector<Component*>::iterator i = Components.begin(); i != Components.end(); i++)
		if (component == *i)
		{
			Components.erase(i);
			break;
		}
}
