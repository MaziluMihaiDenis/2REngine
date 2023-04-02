#pragma once

#include "Object.h"
#include "Component.h"
#include <string>

class EmptyWorldObject : public Object
{
private:
	std::vector<EmptyWorldObject*> Children;
	std::vector<Component*> Components;
	EmptyWorldObject* Parent;
public:
	char* Name;

public:
	virtual void Start();
	virtual void Loop(float deltaTime) override;

public:
	template<typename T>
	void AddComponent();

	void RemoveComponent(Component* component);

	template<typename T>
	T* GetComponent();

public:
	void AddChild(EmptyWorldObject* child);
	void RemoveChild(EmptyWorldObject* child);
	std::vector<EmptyWorldObject*> GetChildren();
	Object* GetChildByName(const char* name);
	/// 0 = first child
	Object* GetChildByIndex(int index);
	void SetParent(EmptyWorldObject* wObj);
	template<typename T>
	T* GetParent();
};

template<typename T>
inline void EmptyWorldObject::AddComponent()
{
	Component* component;
	component = new Component();
	Components.push_back(component);
}

template<typename T>
inline T* EmptyWorldObject::GetComponent()
{
	for (Component* comp : Components)
		if (NAME_OF_CLASS(*comp) == NAME_OF_CLASS(T))
			return comp;
	return nullptr;
}

template<typename T>
inline T* EmptyWorldObject::GetParent()
{
	return (T*)Parent;
}
