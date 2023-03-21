#pragma once

#include "../Types/RECore.h"
#include <vector>

class WindowManager
{
	friend int main();
	friend class Engine;

private:
	static inline WindowManager* Instance;

	void InitWindow();
public:
	struct REWindow* AddWindow(struct REWindowSettings* settings, const char* name, struct REWindow* share, DBool fullscreen);
	bool CloseWindow(struct REWindow* window);
	struct REWindow* GetWindow(int index);
public:
	static WindowManager* GetInstance();
};
