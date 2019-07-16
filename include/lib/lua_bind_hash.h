#pragma once
#include <switch_min.h>

uint64_t lua_bind_hash(const void* data_, size_t len);
uint64_t lua_bind_hash_str(const char* str);