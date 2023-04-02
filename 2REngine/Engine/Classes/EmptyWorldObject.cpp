#include "EmptyWorldObject.h"

void EmptyWorldObject::Start()
{
	return;
}

void EmptyWorldObject::Loop(float deltaTime)
{
	for (EmptyWorldObject*& child : Children)
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

void EmptyWorldObject::AddChild(EmptyWorldObject* child)
{
	child->SetParent(this);
}

void EmptyWorldObject::RemoveChild(EmptyWorldObject* child)
{
	for (std::vector<EmptyWorldObject*>::iterator i = Children.begin(); i != Children.end(); i++)
		if (child == *i)
		{
			Children.erase(i);
			break;
		}
	child->SetParent(nullptr);
}

std::vector<EmptyWorldObject*> EmptyWorldObject::GetChildren()
{
	return Children;
}

Object* EmptyWorldObject::GetChildByName(const char* name)
{
	for(EmptyWorldObject* child : Children)
		if(child->Name == name)
			return child;
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
