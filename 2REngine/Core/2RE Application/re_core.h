#pragma once
#include "../DataTypes/dstring.h"
#include "../DataTypes/dvector2D.h"
#include "2re_platform.h"

typedef struct REWindowSettings REWindowSettings;
typedef struct RELibrary RELibrary;
typedef struct REPlatform REPlatform;
typedef struct REWindow REWindow;

struct REWindowSettings
{
	DString name;
	DVector2D posx, posy;
	DVector2D width, height;
	int style;
};

struct RELibrary
{
	PLATFORM_LIBRARY
};

struct REPlatform
{
	DBool(platform_init)();
	REWindow(platform_create_window)(REWindowSettings*);
};

struct REWindow
{
	REWindow* share;
	DBool fullscreen;
	REWindowSettings settings;

	PLATFORM_WINDOW
};

RELibrary* relib;

REWindow* re_create_window(DVector2D size, DString name, DBool fullscreen, REWindow* share);
