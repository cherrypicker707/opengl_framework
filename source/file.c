#include "file.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

char *fileGetContent(const char *path)
{
    FILE *file = fopen(path, "r");
    assert(file);

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(size + 1);
    assert(content);

    fread(content, 1, size, file);
    fclose(file);

    content[size] = '\0';

    return content;
}
