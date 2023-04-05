#include "win32_core.h"
#include "../internal.h"

unsigned char previousKeyState[256];

void _win32_process_input(UINT Msg)
{
	unsigned char keys[256];

	if (!GetKeyboardState(keys))
		return;

	if (relib.callbacks.key == NULL)
		return;

	for (int i = 32; i <= 96; i++)
	{
		if (Msg == WM_KEYDOWN && GetAsyncKeyState(i))
		{
			if (GetAsyncKeyState(i) != previousKeyState[i])
				relib.callbacks.key(i, 1);
			relib.callbacks.key(i, 2);
		}
		else if (Msg == WM_KEYUP && previousKeyState[i] != keys[i])
			relib.callbacks.key(i, 0);

		previousKeyState[i] = GetAsyncKeyState(i);
	}
}