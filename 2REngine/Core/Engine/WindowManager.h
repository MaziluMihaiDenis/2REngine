#pragma once

#include "../core.h"
#include <vector>

class WindowManager
{
	friend int main();

private:
	static inline WindowManager* WindowManagerInstance;

	void InitWindow();
public:
	struct REWindow* AddWindow(struct REWindowSettings* settings, struct REWindow* share, DBool fullscreen);
	bool CloseWindow(struct REWindow* window);
	struct REWindow* GetWindow(int index);
public:
	static WindowManager* GetWindowManager();
};
