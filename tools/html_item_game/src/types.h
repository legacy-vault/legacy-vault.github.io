// Legacy Vault.
// html_item_game.
// types.h.
// Last Edited on 2017-02-02.
// Version 1.4.

#ifndef TYPES_H
#define TYPES_H
#include "const.h"

// Types
typedef struct char128 { char text[128] } char128; // char128 is a String of 128 Chars
typedef struct line { char text[1024 * 64] } line; // String of 64 KiB

#endif
