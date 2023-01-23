#pragma once

#include "../Data Types/dstring.h"
#include <stdio.h>

// .CFG FILES

// reading
inline FILE* get_property(const char* filename, const char* property)
{
    FILE* file;
    char fileContent[100] = { 0 };

    if ((file = fopen(filename, "r")) == NULL)
        return NULL;

    do
    {
        fscanf(file, "%s%s", &fileContent, &fileContent[98]);
        if (strcmp(fileContent, property) == 0)
            break;
        fscanf(file, "%s", &fileContent);
    } while (1);

    if (strcmp(fileContent, property) != 0)
        return NULL;

    return file;
}

inline int get_property_value_as_int(const char* filename, const char* property)
{
    FILE* file;
    int n;

    if (!(file = get_property(filename, property)))
        return -1;

    fscanf(file, "%d", &n);

    fclose(file);

    return n;
}

inline int get_property_value_as_string(const char* filename, const char* property)
{
    return 0;
}

// writing
DBool add_property_value_as_int(const char* filename, const char* property_name, int value);
DBool add_property_value_as_string(const char* filename, const char* property_name, DString string);