#pragma once

#include <switch_min.h>

#define ANCHOR_REL 0x70ffffc000
extern u64 ANCHOR_ABS;
#define IMPORT(x) (x - ANCHOR_REL + ANCHOR_ABS)

int SaltySD_function_replace(u64 addr, u64 new_func);
int SaltySD_function_replace_sym(char* function_sym, u64 new_func);