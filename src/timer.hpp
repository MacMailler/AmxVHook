#pragma once
#include "amxvhook.hpp"

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
			std::string funcname;
			std::stack<boost::variant<cell, std::string>> params;
		};

		class Pool : boost::noncopyable {
		private:
			cell currTimerId;
			std::map<cell, boost::shared_ptr<Timer>> pool;

		public:
			static const cell minTimerId = 0x80000001;
			static const cell maxTimerId = 0x7FFFFFFE;
			static const cell invalidTimerId = 0x80000000;

			Pool();
			~Pool();

			cell add(boost::shared_ptr<Timer> &);
			bool drop(cell);
			bool stop(cell, bool);
			bool stopped(cell);
			bool contains(cell);
			void clear();
			void clearByAmx(AMX *);
			bool setData(cell, std::stack<boost::variant<cell, std::string>> &);
			bool setInterval(cell, ucell);

			void process();

			static bool isValidTimer(cell id) { return !((id > minTimerId) && (id > maxTimerId)); }
		};
	};
};