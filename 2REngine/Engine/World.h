#pragma once

struct Timer
{
	float TimeLeft;
	float Duration;
	bool Loop;

	Timer(float Duration, bool Loop);
};

class World
{
private:
	inline static World* Instance;
public:

public:
	static World* GetInstance();
};

