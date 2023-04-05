#pragma once

#pragma region INCLUDES


#if defined(__cplusplus)
extern "C"
{
#endif

#include <Basic/filesystem.h>
#include <Basic/color.h>
#include <Basic/math.h>
#include <Application/Core/internal.h>
#include <External/Glad/glad.h>
#include <External/stb_image/stb_image.h>
#include <Debug/debug.h>

#if defined(__cplusplus)
};
#endif

#pragma endregion

#pragma region PATHS

#define SAVED_PATH "C:\\Users\\Giorno\\AppData\\Local"
#define CONFIG_PATH "C:\\Users\\Giorno\\AppData\\Local\\Config\\engine.ini"
#define CONFIG_WINDOW_WIDTH "window\\width"
#define CONFIG_WINDOW_HEIGHT "window\\height"
#define CONFIG_WINDOW_TITLE "window\\title"
#define APPLICATION_TITLE "MyLifeBeLike"
#define NICE_COLOR .11f, .17f, .19f, 1.f

#pragma endregion

#pragma region KEYS

#define RE_KEY_UP 0
#define RE_KEY_PRESS 1
#define RE_KEY_HOLD 2

#define RE_KEY_SPACE              32
#define RE_KEY_APOSTROPHE         39  
#define RE_KEY_COMMA              44  
#define RE_KEY_MINUS              45  
#define RE_KEY_PERIOD             46  
#define RE_KEY_SLASH              47  
#define RE_KEY_0                  48
#define RE_KEY_1                  49
#define RE_KEY_2                  50
#define RE_KEY_3                  51
#define RE_KEY_4                  52
#define RE_KEY_5                  53
#define RE_KEY_6                  54
#define RE_KEY_7                  55
#define RE_KEY_8                  56
#define RE_KEY_9                  57
#define RE_KEY_SEMICOLON          59  
#define RE_KEY_EQUAL              61  
#define RE_KEY_A                  65
#define RE_KEY_B                  66
#define RE_KEY_C                  67
#define RE_KEY_D                  68
#define RE_KEY_E                  69
#define RE_KEY_F                  70
#define RE_KEY_G                  71
#define RE_KEY_H                  72
#define RE_KEY_I                  73
#define RE_KEY_J                  74
#define RE_KEY_K                  75
#define RE_KEY_L                  76
#define RE_KEY_M                  77
#define RE_KEY_N                  78
#define RE_KEY_O                  79
#define RE_KEY_P                  80
#define RE_KEY_Q                  81
#define RE_KEY_R                  82
#define RE_KEY_S                  83
#define RE_KEY_T                  84
#define RE_KEY_U                  85
#define RE_KEY_V                  86
#define RE_KEY_W                  87
#define RE_KEY_X                  88
#define RE_KEY_Y                  89
#define RE_KEY_Z                  90
#define RE_KEY_LEFT_BRACKET       91  
#define RE_KEY_BACKSLASH          92  
#define RE_KEY_RIGHT_BRACKET      93  
#define RE_KEY_GRAVE_ACCENT       96  

//#define GLFW_KEY_ESCAPE             256
//#define GLFW_KEY_ENTER              257
//#define GLFW_KEY_TAB                258
//#define GLFW_KEY_BACKSPACE          259
//#define GLFW_KEY_INSERT             260
//#define GLFW_KEY_DELETE             261
//#define GLFW_KEY_RIGHT              262
//#define GLFW_KEY_LEFT               263
//#define GLFW_KEY_DOWN               264
//#define GLFW_KEY_UP                 265
//#define GLFW_KEY_PAGE_UP            266
//#define GLFW_KEY_PAGE_DOWN          267
//#define GLFW_KEY_HOME               268
//#define GLFW_KEY_END                269
//#define GLFW_KEY_CAPS_LOCK          280
//#define GLFW_KEY_SCROLL_LOCK        281
//#define GLFW_KEY_NUM_LOCK           282
//#define GLFW_KEY_PRINT_SCREEN       283
//#define GLFW_KEY_PAUSE              284
//#define GLFW_KEY_F1                 290
//#define GLFW_KEY_F2                 291
//#define GLFW_KEY_F3                 292
//#define GLFW_KEY_F4                 293
//#define GLFW_KEY_F5                 294
//#define GLFW_KEY_F6                 295
//#define GLFW_KEY_F7                 296
//#define GLFW_KEY_F8                 297
//#define GLFW_KEY_F9                 298
//#define GLFW_KEY_F10                299
//#define GLFW_KEY_F11                300
//#define GLFW_KEY_F12                301
//#define GLFW_KEY_F13                302
//#define GLFW_KEY_F14                303
//#define GLFW_KEY_F15                304
//#define GLFW_KEY_F16                305
//#define GLFW_KEY_F17                306
//#define GLFW_KEY_F18                307
//#define GLFW_KEY_F19                308
//#define GLFW_KEY_F20                309
//#define GLFW_KEY_F21                310
//#define GLFW_KEY_F22                311
//#define GLFW_KEY_F23                312
//#define GLFW_KEY_F24                313
//#define GLFW_KEY_F25                314
//#define GLFW_KEY_KP_0               320
//#define GLFW_KEY_KP_1               321
//#define GLFW_KEY_KP_2               322
//#define GLFW_KEY_KP_3               323
//#define GLFW_KEY_KP_4               324
//#define GLFW_KEY_KP_5               325
//#define GLFW_KEY_KP_6               326
//#define GLFW_KEY_KP_7               327
//#define GLFW_KEY_KP_8               328
//#define GLFW_KEY_KP_9               329
//#define GLFW_KEY_KP_DECIMAL         330
//#define GLFW_KEY_KP_DIVIDE          331
//#define GLFW_KEY_KP_MULTIPLY        332
//#define GLFW_KEY_KP_SUBTRACT        333
//#define GLFW_KEY_KP_ADD             334
//#define GLFW_KEY_KP_ENTER           335
//#define GLFW_KEY_KP_EQUAL           336
//#define GLFW_KEY_LEFT_SHIFT         340
//#define GLFW_KEY_LEFT_CONTROL       341
//#define GLFW_KEY_LEFT_ALT           342
//#define GLFW_KEY_LEFT_SUPER         343
//#define GLFW_KEY_RIGHT_SHIFT        344
//#define GLFW_KEY_RIGHT_CONTROL      345
//#define GLFW_KEY_RIGHT_ALT          346
//#define GLFW_KEY_RIGHT_SUPER        347
//#define GLFW_KEY_MENU               348

#pragma endregion