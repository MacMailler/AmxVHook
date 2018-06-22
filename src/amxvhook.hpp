#pragma once
#pragma warning(disable:4996 4244)
#pragma comment(lib, "ScriptHookV.lib")

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <queue>
#include <string>
#include <unordered_map>

#include <boost\filesystem.hpp>
#include <boost\thread\thread.hpp>
#include <boost\thread\mutex.hpp>
#include <boost\algorithm\string.hpp>
#include <boost\make_shared.hpp>

#include <sdk\main.h>
#include <sdk\types.h>
#include <sdk\enums.h>
#include <sdk\natives.h>
#include <sdk\nativeCaller.h>

#define HAVE_STDINT_H
#include "amx\amx.h"
#include "amx\amxaux.h"

#include "pool.hpp"
#include "core.hpp"
#include "debug.hpp"
#include "funcs.hpp"
#include "natives.hpp"
#include "keyboard.hpp"
#include "string.hpp"