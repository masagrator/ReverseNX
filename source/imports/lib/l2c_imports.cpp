#include <switch_min.h>

#include "lib/l2c_imports.h"
#include "lib/lua_bind_hash.h"
#include "useful/useful.h"

//==================================//
//============== lib ===============//
//==================================//
int lib::lua_const(const char* str) {
	int val;
	if (lib::lua_bind_get_value(lua_bind_hash_str(str), &val))
		return val;
	else
		return -1;
}

//==================================//
//========= lib::L2CValue ==========//
//==================================//
lib::L2CValue::L2CValue() {}
lib::L2CValue::L2CValue(bool val) {
	type = L2C_bool;
	raw = val;
}
lib::L2CValue::L2CValue(int val) {
	type = L2C_integer;
	raw = val;
}
lib::L2CValue::L2CValue(u64 val) {
	type = L2C_integer;
	raw = val;
}
lib::L2CValue::L2CValue(float val) {
	type = L2C_number;
	raw_float = val;
}
lib::L2CValue::L2CValue(double val) {
	type = L2C_number;
	raw_float = val;
}
lib::L2CValue::L2CValue(const char* str) {
	type = L2C_void;
}

//==================================//
//========= lib::L2CAgent ==========//
//==================================//
void lib::L2CAgent::get_lua_stack(int index, lib::L2CValue* l2c_val) {
	asm("mov x8, %x0" : : "r"(l2c_val) : "x8" );
	lib::L2CAgent::pop_lua_stack(index);
}
u64 lib::L2CAgent::_clear_lua_stack() {
	u64 lua_state, v2, i;
	lua_state = this->lua_state_agent;
	
	v2 = LOAD64(lua_state + 16);
	for (i = LOAD64(LOAD64((lua_state + 32))) + 16LL; v2 < i; v2 = LOAD64(lua_state + 16)) {
		LOAD64(lua_state + 16) = v2 + 16;
		*(__int32_t *)(v2 + 8) = 0;
	}
	LOAD64(lua_state + 16) = i;
	return (u64)this;
}