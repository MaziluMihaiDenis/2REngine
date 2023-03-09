#include "StringFunctions.h"
#include <malloc.h>
//#include <cstdlib>

// TODO: Rework

wchar_t* char_to_wchar_t(char* string)
{
	/*wchar_t* wstring = malloc(strlen(string) * sizeof(wchar_t));
	mbstowcs(wstring, string, strlen(string) * sizeof(wchar_t));
	return wstring;*/
	return NULL;
}

/*
void ucharcpy(unsigned char* destination, const unsigned char* source)
{
	int i;

	destination = malloc(strlen(source) + 1);

	for (i = 0; source[i] != '\0'; i++)
		destination[i] = source[i];

	destination[i] = '\0';
}

void strcpycnt(char* destination, const char* source, int cnt)
{
	int i;

	destination = malloc(cnt + 1);

	for (i = 0; i < cnt; i++)
		destination[i] = source[i];

	destination[i] = '\0';
}
*/

