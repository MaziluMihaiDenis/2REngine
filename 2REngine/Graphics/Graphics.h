#pragma once

#include <Engine/Classes/SpriteComponent.h>
#include <vector>

class Graphics
{
	friend class Engine;
private:
	static inline Graphics* Instance;
	std::vector<SpriteComponent*> RegisteredObjects;

public:
	void Init();
	void Loop();
public:
	void RegisterDisplayObject(SpriteComponent* object);
	void UnregisterDisplayObject(SpriteComponent* object);
public:
	static Graphics* GetInstance();
};
