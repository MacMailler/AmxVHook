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

			ucell interval;
			ucell lastTime;

			AMX * amx;
			int funcindex;
			AmxArgs params;
		};

		class Pool : NonCopy {
		private:
			Id ident;
			uint32_t currTimerId = 0;
			std::map<cell, std::shared_ptr<Timer>> pool;

		public:
			Pool();
			~Pool();

			cell add(std::shared_ptr<Timer> &);
			bool drop(cell);
			bool stop(cell, bool);
			bool stopped(cell);
			bool contains(cell);
			void clear();
			void clearByAmx(AMX *);
			bool setData(cell, AmxArgs &);
			bool setInterval(cell, ucell);
			cell getCurrId();

			void process();
		};
	};
};