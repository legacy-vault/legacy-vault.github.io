// Legacy Vault
// html_item_game
// types.h
// Version 1.3

#ifndef TYPES_H
#define TYPES_H
#include "const.h"

// Types
typedef struct char128 { char text[128] } char128; // char128 is a String of 128 Chars
typedef struct line { char text[1024 * 64] } line; // String of 64 KiB

#endif
