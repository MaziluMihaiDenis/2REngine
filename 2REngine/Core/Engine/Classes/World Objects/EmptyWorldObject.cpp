#include "EmptyWorldObject.h"

void EmptyWorldObject::Start()
{
}

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

void EmptyWorldObject::AddChild(Object* child)
{
}

void EmptyWorldObject::RemoveChild(Object* child)
{
}

std::vector<Object> EmptyWorldObject::GetChildren()
{
	return std::vector<Object>();
}

Object* EmptyWorldObject::GetChildByName(const char* name)
{
	return nullptr;
}

Object* EmptyWorldObject::GetChildByIndex(int index)
{
	return nullptr;
}

void EmptyWorldObject::SetParent(EmptyWorldObject* wObj)
{
	Parent = wObj;
}
