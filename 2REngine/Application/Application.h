#pragma once
extern "C"
{
#include "Core/internal.h"
}
#include <Basic/color.h>

class Application
{
	friend class Graphics;
private:
	inline static Application* Instance;
	Color BackgroundColor;
public:
	REWindow* InstanceWindow(REWindowSettings* settings, const char* title, REWindow* share, bool fullscreen);
	REWindow* GetWindowAt(int index);
	void DestroyWindow(REWindow* window);
public:
	bool IsRunning();
	void Init();
	void Loop();
	void SetBackgroundColor(float red, float green, float blue, float alpha);

public:
	static Application* GetInstance();
	REWindow* GetWindowInstance();
};

