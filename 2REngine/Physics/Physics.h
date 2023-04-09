#pragma once

#include "Structs/CollisionShape2D.h"
#include <vector>

class Physics
{
	friend class Engine;
	friend int main();
	
private:
	inline static Physics* Instance;
	std::vector<CollisionShape2D*> RegisteredColliders;

private:
	void Init();
	void Loop();

	void HandleRRCollision();
	void HandleRCCollision();
	void HandleCCCollision();

	bool testCollision(float );
public:
	void RegisterCollider(CollisionShape2D* collider);
	void UnregisterCollider(CollisionShape2D* collider);

public:
	static Physics* GetInstance();
};

