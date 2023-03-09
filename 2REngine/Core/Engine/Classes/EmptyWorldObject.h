#pragma once

#include "Object.h"
#include "Component.h"

class EmptyWorldObject : public Object
{
private:
	std::vector<Object*> Children;
	std::vector<Component*> Components;
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
	void AddChild(Object* child);
	void RemoveChild(Object* child);
	std::vector<Object> GetChildren();
	Object* GetChildByName(const char* name);
	/// 0 = first child
	Object* GetChildByIndex(int index);
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
	for(Component* comp : Components)
		if()
	return nullptr;
}
