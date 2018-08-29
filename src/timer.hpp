#pragma once
#include "amxvhook.hpp"
#include "id.hpp"

#define TIMER_CODE_DROP 0
#define TIMER_CODE_CONT 1
#define TIMER_CODE_PAUSE 2

namespace AmxVHook {
	namespace Timer {
		struct Timer {
			bool stop;

			uint32_t interval;
			uint32_t lastTime;

			AMX * amx;
			int funcindex;
			AmxArgs params;
		};

		class Pool : NonCopy {
		private:
			Id ident;
			uint32_t currTimerId = 0;
			std::map<uint32_t, std::shared_ptr<Timer>> pool;

		public:
			Pool();
			~Pool();

			uint32_t add(std::shared_ptr<Timer> &);
			bool drop(uint32_t);
			bool stop(uint32_t, bool);
			bool stopped(uint32_t);
			bool contains(uint32_t);
			void clear();
			void clearByAmx(AMX *);
			bool setData(uint32_t, AmxArgs &);
			bool setInterval(uint32_t, uint32_t);
			uint32_t getCurrId();

			void process();
		};
	};
};