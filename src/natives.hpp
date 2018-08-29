#pragma once
#include "amxvhook.hpp"

#define argscount()	(params[0] / sizeof(cell))
#define checkargs(n) if (argscount() != n) return 0;

#define MOD_NATIVE(native) cell AMX_NATIVE_CALL native(AMX *amx, const cell *params)
#define MOD_DEFINE_NATIVE(native) {#native, native},

#include "natives\core.hpp"
#include "natives\blip.hpp"
#include "natives\player.hpp"
#include "natives\ped.hpp"
#include "natives\ui.hpp"
#include "natives\graphics.hpp"
#include "natives\vehicle.hpp"
#include "natives\checkpoint.hpp"
#include "natives\input.hpp"
#include "natives\gameplay.hpp"
#include "natives\entity.hpp"
#include "natives\camera.hpp"
#include "natives\time.hpp"
#include "natives\weapon.hpp"
#include "natives\streaming.hpp"
#include "natives\audio.hpp"
#include "natives\misc.hpp"