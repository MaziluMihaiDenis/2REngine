#pragma once

class World
{
private:
	inline static World* Instance;

public:
	static World* GetInstance();
};

