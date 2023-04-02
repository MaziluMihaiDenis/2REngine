#pragma once

#include <string.h>

#ifndef UNICODE
#define UNICODE
#endif

wchar_t* char_to_wchar_t(char *string);
/*
void ucharcpy(unsigned char* destination, const unsigned char* source);
void strcpycnt(char* destination, const char* source, int cnt);
*/
char* remove_file_extension(const char* name);
char* extract_path(const char* filepath);
char* extract_name(const char* filepath);