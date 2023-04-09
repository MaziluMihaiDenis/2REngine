#include "string_functions.h"
#include <stdlib.h>
#include <Basic/core.h>

wchar_t* char_to_wchar_t(char string[256])
{
	int size = strlen(string) + 1;
	wchar_t wstring[256];
	mbstowcs(wstring, string, size);
	return wstring;
}

char* _extract_path(const char* filepath)
{
	char *p, *n, cpy[256], unformattedCpy[256];

	strcpy(cpy, filepath);
	strcpy(unformattedCpy, filepath);

	p = strtok(cpy, "\\/");
	n = p;

	while (p != NULL)
	{
		p = strtok(NULL, "\\/");
		if (p != NULL)
			n = p;
	}

	unformattedCpy[strlen(unformattedCpy) - strlen(n) - 1] = '\0';

	return unformattedCpy;
}

char* _remove_file_extension(const char* name)
{
	return strtok(name, ".");
}

char* _extract_name(const char* filepath)
{
	char* p, * n, cpy[256];

	strcpy(cpy, filepath);

	p = strtok(cpy, "\\/");
	n = p;

	while (p != NULL)
	{
		p = strtok(NULL, "\\/");
		if (p != NULL)
			n = p;
	}

	return n;
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

