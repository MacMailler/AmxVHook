#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	namespace Core {

		extern bool versionVisible;
		static const uint32_t AMXVHOOK_VERSION = 0x01;

		void init();
		void cleanup();

		cell getFps();
	};
};