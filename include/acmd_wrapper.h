#ifndef ACMD_WRAPPER_H
#define ACMD_WRAPPER_H

#include <switch_min.h>

#include "app/sv_animcmd.h"
#include "app/sv_system.h"
#include "app/lua_bind.h"
#include "lib/l2c_imports.h"

#include <initializer_list>

u64 load_module(u64 module_accessor, u64 module_offset);
void* load_module_impl(u64 module, u64 function_offset);
bool is_before_frame(u64 lua_state, float f);

struct ACMD {
	lib::L2CAgent* l2c_agent;
	u64 module_accessor;

	ACMD(lib::L2CAgent* agent);

	void frame(float f);
	// attempted reimplementation of sv_animcmd::frame
	bool _frame(float f);
	void wait(float f);
	
	bool is_excute();
	void wrap(u64 (*acmd_func)(u64), std::initializer_list<lib::L2CValue> list);
	void ATTACK(
		u64 i1,  // ID
		u64 i2,  // Part
		u64 h1,  // Bone
		float f1,  // Damage
		u64 i3,  // Angle
		u64 i4,  // KBG
		u64 i5,  // FKB
		u64 i6,  // BKB
		float f2,  // Size
		float f3,  // X
		float f4,  // Y
		float f5,  // Z
		// X2
		// Y2
		// Z2
		float f6,  // Hitlag
		float f7,  // SDI
		u64 i7,  // Clang/Rebound
		u64 i8,  // Facing Restriction
		u64 i9,  // Fixed Weight
		u64 i10, // Shield Damage
		float f8,  // Trip Chance
		u64 i11, // Rehite Rate
		u64 i12, // Reflectable
		u64 i13, // Absorbable
		u64 i14, // Flinchless
		u64 i15, // Disable Hitlag
		u64 i16, // Direct
		u64 i17, // Ground/Air
		u64 i18, // Hit Bits
		u64 i19, // Collision Bits
		u64 i20, // Friendly Fire
		u64 h2,  // Effect
		u64 i21, // SFX Level
		u64 i22, // SFX Type
		u64 i23);

	void ATTACK(
		u64 i1,  // ID
		u64 i2,  // Part
		u64 h1,  // Bone
		float f1,  // Damage
		u64 i3,  // Angle
		u64 i4,  // KBG
		u64 i5,  // FKB
		u64 i6,  // BKB
		float f2,  // Size
		float f3,  // X
		float f4,  // Y
		float f5,  // Z
		float fX2, // X2
		float fY2, // Y2
		float fZ2, // Z2
		float f6,  // Hitlag
		float f7,  // SDI
		u64 i7,  // Clang/Rebound
		u64 i8,  // Facing Restriction
		u64 i9,  // Fixed Weight
		u64 i10, // Shield Damage
		float f8,  // Trip Chance
		u64 i11, // Rehite Rate
		u64 i12, // Reflectable
		u64 i13, // Absorbable
		u64 i14, // Flinchless
		u64 i15, // Disable Hitlag
		u64 i16, // Direct
		u64 i17, // Ground/Air
		u64 i18, // Hit Bits
		u64 i19, // Collision Bits
		u64 i20, // Friendly Fire
		u64 h2,  // Effect
		u64 i21, // SFX Level
		u64 i22, // SFX Type
		u64 i23);
};

#endif // ACMD_WRAPPER_H
