#pragma once
#include "useful/useful.h"

#include "lua_bind/MotionModule.h"
#include "lua_bind/ControlModule.h"
#include "lua_bind/CancelModule.h"
#include "lua_bind/EffectModule.h"
#include "lua_bind/WorkModule.h"
#include "lua_bind/StatusModule.h"
#include "lua_bind/KineticModule.h"
#include "lua_bind/JostleModule.h"
#include "lua_bind/GroundModule.h"
#include "lua_bind/GrabModule.h"
#include "lua_bind/DamageModule.h"
#include "lua_bind/CatchModule.h"
#include "lua_bind/CaptureModule.h"
#include "lua_bind/PostureModule.h"
#include "lua_bind/ArticleModule.h"
#include "lua_bind/ColorBlendModule.h"
#include "lua_bind/SoundModule.h"
#include "lua_bind/StopModule.h"
#include "lua_bind/ShakeModule.h"
#include "lua_bind/ShieldModule.h"
#include "lua_bind/SlopeModule.h"
#include "lua_bind/SlopeModule.h"
#include "lua_bind/ShadowModule.h"
#include "lua_bind/SlowModule.h"
#include "lua_bind/TurnModule.h"
#include "lua_bind/VisibilityModule.h"
#include "lua_bind/TeamModule.h"
#include "lua_bind/SearchModule.h"
#include "lua_bind/ReflectorModule.h"
#include "lua_bind/ReflectModule.h"
#include "lua_bind/PhysicsModule.h"
#include "lua_bind/MotionAnimcmdModule.h"
#include "lua_bind/ModelModule.h"
#include "lua_bind/ItemModule.h"
#include "lua_bind/InkPaintModule.h"
#include "lua_bind/HitModule.h"
#include "lua_bind/ComboModule.h"
#include "lua_bind/CameraModule.h"
#include "lua_bind/AttackModule.h"
#include "lua_bind/AreaModule.h"
#include "lua_bind/AbsorberModule.h"

#include "lua_bind/FighterWorkModuleImpl.h"
#include "lua_bind/FighterStopModuleImpl.h"
#include "lua_bind/FighterStatusModuleImpl.h"
#include "lua_bind/FighterMotionModuleImpl.h"
#include "lua_bind/FighterControlModuleImpl.h"
#include "lua_bind/FighterAreaModuleImpl.h"

namespace app::lua_bind {
	namespace FighterManager {
		u64 get_fighter_information(u64, int) asm("_ZN3app8lua_bind44FighterManager__get_fighter_information_implEPNS_14FighterManagerENS_14FighterEntryIDE") LINKABLE;
	}

	namespace FighterInformation {
		bool is_operation_cpu(u64) asm("_ZN3app8lua_bind41FighterInformation__is_operation_cpu_implEPNS_18FighterInformationE") LINKABLE;
	}
}