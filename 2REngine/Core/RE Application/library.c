#include "internal.h"

DBool re_init()
{
#if defined(_WIN32)
	_win32_connect();
#endif

	if (!relib.platform.platform_init())
		return FALSE;

	return TRUE;
}

void re_terminate()
{

}
