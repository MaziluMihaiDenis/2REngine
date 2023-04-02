#pragma once

#include <Engine/Classes/DisplayComponent.h>
#include <vector>

class Graphics
{
	friend class Engine;
private:
	static inline Graphics* Instance;
	std::vector<DisplayComponent*> RegisteredObjects;

public:
	void Init();
	void Loop();
public:
	void RegisterDisplayObject(DisplayComponent* object);
	void UnregisterDisplayObject(DisplayComponent* object);
public:
	static Graphics* GetInstance();
};
