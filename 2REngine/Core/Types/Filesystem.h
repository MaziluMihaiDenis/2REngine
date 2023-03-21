#pragma once
#include <stdio.h>

#define MAX_FILE_DIMM 3000

/* 
	creates a directory at the specified path with the specified name
	reutrns 1 for success, 0 path not found, -1 directory already exists
*/
int sys_mkdir(const char* path, const char* dir_name);

// files
/*
	writes the specified contents in a file
	returns 1 for success, 0 for failure
*/
int sys_write_file(const char* path, const char* format, ...);

/*
	gets a property's value from a file 
	reutrns -1 for failure
*/
int sys_get_file_property_as_int(const char* path, const char* property);

char* sys_get_file_property_as_string(const char* path, const char* property);
float sys_get_file_property_as_float(const char* path, const char* property);

/*
	finds a property inside a file
	returns 1 for success, 0 for failure
*/
int _find_property(FILE** file, const char* path, const char* property);

/*
	returns the contents of a file as a string
*/
char* get_file_contents(const char* filename);