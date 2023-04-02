#pragma once

class Engine
{
	friend int main();

private:
	inline static Engine* Instance;

private:
	void Init();
	void Loop(float deltaTime);
	void End();
public:
	static Engine* GetInstance();
};

