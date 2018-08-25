#pragma once
#include "amxvhook.hpp"
#include "natives.hpp"

#define AMXVHOOK_VER		"0.1"
#define AMXVHOOK_VER_INT	0x01

namespace AmxVHook {
	namespace Core {
		extern bool versionVisible;

		void init();
		void cleanup();

		ucell getFps();
	};
};