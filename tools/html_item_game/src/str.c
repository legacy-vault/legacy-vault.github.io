// Legacy Vault
// html_item_game
// str.c
// Version 1.2

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "const.h"
#include "str.h"

char *createPath ( char *filePath, int size, char *a, char *b, char *fileName )
{
    if ( (strlen(filePath) + strlen(a) + strlen(b) + strlen(fileName)) < size )
    {
        strcpy(filePath, a);
        strcat(filePath, b);
        strcat(filePath, fileName);
    }
    else
    {
        printf("Path is too long. Max size = [%i]!\n", size);
        return NULL;
    }
    printf("%s\n", filePath);
    return filePath;
}

char *createPath2 ( char *filePath, int size, char *a, char *b, char *fileName, char *ext )
{
    if ( (strlen(filePath) + strlen(a) + strlen(b) + strlen(fileName) + strlen(ext)) < size )
    {
        strcpy(filePath, a);
        strcat(filePath, b);
        strcat(filePath, fileName);
        strcat(filePath, ext);
    }
    else
    {
        printf("Path is too long. Max size = [%i]!\n", size);
        return NULL;
    }
    printf("%s\n", filePath);
    return filePath;
}
