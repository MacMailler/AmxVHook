#pragma once
#pragma warning(disable:4996 4244)
#pragma comment(lib, "ScriptHookV.lib")

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <queue>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <filesystem>
#include <thread>
#include <memory>
#include <fstream>
#include <variant>
#include <mutex>
#include <thread>
#include <assert.h>

#include <sdk\main.h>
#include <sdk\types.h>
#include <sdk\enums.h>
#include <sdk\natives.h>
#include <sdk\nativeCaller.h>

#include "amx\amx.h"
#if defined AMXDBG
#include "amx\amxdbg.h"
#endif

#include "noncopy.hpp"
#include "types.hpp"
#include "amxaux.hpp"
#include "pool.hpp"
#include "core.hpp"
#include "log.hpp"
#include "funcs.hpp"
#include "keyboard.hpp"
#include "string.hpp"
#include "timer.hpp"