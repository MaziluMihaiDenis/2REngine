#pragma once
#include "internal.h"
#include "system.h"
#include <direct.h>
#include <stdarg.h>
#include <string.h>

int sys_dir_exists(const char* path)
{
    return 0;
}

int sys_mkdir(const char* path, const char* dir_name)
{
    char* full;
    int success;

    if (!(full = mem_alloc(strlen(path) + strlen(dir_name) + 3, "sys_mkdir_string")))
        return 0;

    success = 0;
    strcpy(full, path);
    strcat(full, "\\");
    strcat(full, dir_name);

    success = _mkdir(full);

    if (errno == EEXIST)
        return -1;

    return (success == 0) ? 1 : 0;
}

int sys_write_file(const char* path, char* format, ...)
{
    char *ptr, cpy[100];
    va_list args;
    FILE* file;

    if ((file = fopen(path, "a")) == NULL)
        return 0;
    strcpy(cpy, format);
    ptr = strtok(cpy, "% ");
    va_start(args, format);

    while (ptr != NULL)
    {
        switch (ptr[0])
        {
        case 's':
            char* a = va_arg(args, char*);
            fprintf(file, "%s", a);
            break;
        case 'd':
            fprintf(file, "%d", va_arg(args, int));
            break;
        case 'f':
            fprintf(file, "%f", va_arg(args, float));
            break;
        }

        ptr = strtok(NULL, "% ");
    }

    va_end(args);

    fprintf(file, "%c", '\n');
    file = fclose(file);

    return 1;
}

int sys_get_file_property_as_int(const char* path, const char* property)
{
    int value;
    FILE* fout;

    if (!_find_property(&fout, path, property))
        return -1;

    fscanf(fout, "%d", &value);

    return value;
}

char* sys_get_file_property_as_string(const char* path, const char* property)
{
    char value[256];
    FILE* fout;

    if (!_find_property(&fout, path, property))
        return -1;

    fscanf(fout, "%s", value);

    return value;
}

float sys_get_file_property_as_float(const char* path, const char* property)
{
    float value;
    FILE* fout;

    if (!_find_property(&fout, path, property))
        return -1;

    fscanf(fout, "%f", &value);

    return value;
}

int _find_property(FILE** file, const char* path, const char* property)
{
    char *ptr, *output, *o;

    if ((*file = fopen(path, "r")) == NULL)
        return 0;

    if((output = mem_alloc(256, "_system_find_property_input")) == NULL)
        return 0;

    while (fscanf(*file, "%s", output))
        if (strcmp(property, output) == 0)
        {
            fscanf(*file, "%s", output);
            return 1;
        }
    return 0;
}
 