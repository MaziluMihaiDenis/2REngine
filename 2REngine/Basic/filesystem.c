#pragma once
#include "filesystem.h"
#include "core.h"
#include "string_functions.h"
#include <direct.h>
#include <stdarg.h>
#include <string.h>
#include <External/stb_image/stb_image.h>
#include <Graphics/Structs/TextureConfig.h>

int sys_dir_exists(const char* path)
{
    return 0;
}

int sys_mkdir(const char* path, const char* dir_name)
{
    char* full;
    int success;

    if (!(full = mem_alloc(strlen(path) + strlen(dir_name) + 3, NAME(full))))
        return 0;

    success = 0;
    strcpy(full, path);
    strcat(full, "\\");
    strcat(full, dir_name);
    FREE(full);

    success = _mkdir(full);

    if (errno == EEXIST)
        return -1;

    return (success == 0) ? 1 : 0;
}

int sys_write_file(const char* path, const char* format, ...)
{
    char *ptr, cpy[100], *a;
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
            a = va_arg(args, char*);
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
    fclose(file);

    return 1;
}

int sys_get_file_property_as_int(const char* path, const char* property)
{
    int value;
    FILE* fout;

    if (!_find_property(&fout, path, property))
        return -1;

    fscanf(fout, "%d", &value);
    fclose(fout);

    return value;
}

char* sys_get_file_property_as_string(const char* path, const char* property)
{
    char value[256];
    FILE* fout;

    if (!_find_property(&fout, path, property))
        return NULL;

    fscanf(fout, "%s", value);
    fclose(fout);

    return value;
}

float sys_get_file_property_as_float(const char* path, const char* property)
{
    float value;
    FILE* fout;

    if (!_find_property(&fout, path, property))
        return -1;

    fscanf(fout, "%f", &value);
    fclose(fout);

    return value;
}

int _find_property(FILE** file, const char* path, const char* property)
{
    char *output;

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
    FREE(output);
    return 0;
}

char* get_file_contents(const char* path)
{
    FILE *file;
    int character, i;
    char* fileCpy;

    if ((file = fopen(path, "r")) == NULL)
        return NULL;

    if (!MALLOC(fileCpy, MAX_FILE_DIMM))
        return NULL;

    i = 0;
    while ((character = fgetc(file)) != EOF)
        fileCpy[i] = (char)character, i++;
    fileCpy[i] = '\0';
    fclose(file);

    return fileCpy;
}

void read_reimptex(const char* path, struct TextureConfig* config)
{
    FILE* file;
    const char* newpath = make_path_to_file(path, ".reimptex");

    if (!(file = fopen(newpath, "r")))
        return;

    fscanf(file, "%d%d%d", &config->Filter, &config->ColorFormat, &config->Wrapping);

    fclose(file);
}

void import_texture(const char* path, struct TextureConfig* config)
{
    FILE* file;
    const char* newpath = make_path_to_file(path, ".reimptex");

    if (!(file = fopen(newpath, "a+")))
        return;

    if (fgetc(file) != EOF)
        return;

    if (config)
        fprintf(file, "%d %d %d", config->Filter, config->ColorFormat, config->Wrapping);
    else
        fprintf(file, "%d %d %d", 0x2600, 0x1908, 0x2901);
    
    fclose(file);
}

const char* make_path_to_file(const char* path, const char* extension)
{
    char *imp_file_path, imp_file_name[256], imp_file_noext[256];
    if (!MALLOC(imp_file_path, 256))
        return NULL;

    strcpy(imp_file_path, extract_path(path));
    strcpy(imp_file_name, extract_name(path));
    strcpy(imp_file_noext, remove_file_extension(imp_file_name));
    strcat(imp_file_path, "/");
    strcat(imp_file_path, imp_file_noext);
    strcat(imp_file_path, extension);

    return imp_file_path;
}
