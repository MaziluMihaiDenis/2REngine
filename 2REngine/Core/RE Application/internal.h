#pragma once
#include "../DataTypes/dstring.h"
#include "../DataTypes/dvector2D.h"
#include "../Logging/logging.h"
#include "platform.h"

typedef struct REWindowSettings REWindowSettings;
typedef struct RELibrary RELibrary;
typedef struct REPlatform REPlatform;
typedef struct REWindow REWindow;

struct REWindowSettings
{
	DString name;
	DVector2D pos;
	DVector2D size;
	int style;
};

struct REPlatform
{
	DBool(*platform_init)();
	void(*platform_terminate)();
	DBool(*platform_create_window)(REWindow*, REWindowSettings*);
	void(*platform_poll_events)();
	void(*platform_free_window)(REWindow*);
};

struct RELibrary
{
	REPlatform platform;
	REWindow* mainWindow;

	PLATFORM_LIBRARY
};


struct REWindow
{
	REWindow* share;
	REWindowSettings* settings;
	DBool fullscreen;
	DBool running;

	PLATFORM_WINDOW
};

RELibrary relib;

DBool re_init();
void re_terminate();

REWindow* re_create_window(DVector2D size, DString name, DBool fullscreen, REWindow* share);
void re_poll_events();
void re_free_window(REWindow* window);
