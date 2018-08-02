#pragma once
#include "amxvhook.hpp"
#include "natives.hpp"

namespace AmxVHook {
	namespace Core {

		extern bool versionVisible;
		static const ucell AMXVHOOK_VERSION = 0x01;

		void init();
		void cleanup();

		ucell getFps();
	};
};