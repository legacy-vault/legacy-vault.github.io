// Legacy Vault
// html_item_game
// main.h
// Version 1.2

#ifndef MAIN_H
#define MAIN_H
#include "types.h"
#include "const.h"
#include <stdbool.h>

// VARIABLES ///////////////////////////////////////////////////////////////

// Strings
extern char *path_cfg;
extern char *path_out;
extern char128 title; // Title of a Game

// TMP
FILE *fp;
char c;
bool blue;
int OK, i, j, j_max, k;
uint64_t fileSize;

#endif
