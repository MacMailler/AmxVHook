#pragma once
#include "amxvhook.hpp"

#define arguments(a) !(params[0] != (a << 2))
#define MOD_NATIVE(native) cell AMX_NATIVE_CALL native(AMX *amx, const cell *params)
#define MOD_DEFINE_NATIVE(native) {#native, native},

#define amxGetAddresses(amx,params,addr,start,count)\
for (int i = 0; i < count; i++)\
		if (amx_GetAddr(amx, params[start + i], &addr[i]) != AMX_ERR_NONE) \
			return 0; \

#define amxAddrToVector3(amx,params,start,count) \
	for (int i = 0; i < count; i++) { \
		if (amx_GetAddr(amx, params[start + i], &addr[i]) != AMX_ERR_NONE) \
			return 0; \
		vec[i] = Funcs::cellArrayToVector3(addr[i]); \
	} \

#include "natives\core.hpp"
#include "natives\blip.hpp"
#include "natives\player.hpp"
#include "natives\ped.hpp"
#include "natives\graphics.hpp"
#include "natives\ui.hpp"
#include "natives\vehicle.hpp"
#include "natives\checkpoint.hpp"
#include "natives\input.hpp"
#include "natives\gameplay.hpp"
#include "natives\entity.hpp"
#include "natives\camera.hpp"