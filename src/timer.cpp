#include "timer.hpp"

namespace AmxVHook {

	extern std::shared_ptr<AmxVHook::Pool> gPool;
	std::shared_ptr<Timer::Pool> gTimer;

	namespace Timer {
		Pool::Pool() {
			currTimerId = 0u;
			ident.reset();
			pool.clear();
		}

		Pool::~Pool() {
			clear();
		}

		uint32_t Pool::add(std::shared_ptr<Timer>& timer) {
			uint32_t id = ident.get();

			pool.insert({ id, std::move(timer) });

			return id;
		}

		bool Pool::drop(uint32_t id) {
			if (!contains(id))
				return false;

			pool[id].reset();
			pool.erase(id);
			ident.remove(id);

			return true;
		}

		bool Pool::stop(uint32_t id, bool stop) {
			if (!contains(id))
				return false;

			pool[id]->stop = stop;

			return true;
		}

		bool Pool::stopped(uint32_t id) {
			if (!contains(id))
				return false;

			return pool[id]->stop;
		}

		bool Pool::contains(uint32_t id) {
			return pool.find(id) == pool.end();
		}

		void Pool::clear() {
			for (auto& i : pool) {
				i.second.reset();
				pool.erase(i.first);
			}

			ident.reset();
		}

		void Pool::clearByAmx(AMX* amx) {
			for (const auto& i : pool) {
				if (i.second->amx == amx) {
					pool.erase(i.first);
					ident.remove(i.first);
				}
			}
		}

		bool Pool::setData(uint32_t id, AmxArgs& params) {
			if (!contains(id))
				return false;
			
			pool[id]->params = std::move(params);

			return true;
		}

		bool Pool::setInterval(uint32_t id, uint32_t interval) {
			if (!contains(id))
				return false;

			pool[id]->interval = interval;

			return true;
		}

		uint32_t Pool::getCurrId() {
			return currTimerId;
		}

		void Pool::process() {
			for (const auto& i : pool) {
				if (i.second->stop) continue;

				if ((GAMEPLAY::GET_GAME_TIMER() - i.second->lastTime) >= i.second->interval) {
					currTimerId = i.first;
					switch (gPool->execByIndex(i.second->amx, i.second->funcindex, &i.second->params)) {
					case TIMER_CODE_DROP:
						pool.erase(i.first);
						break;
					
					case TIMER_CODE_STOP :
						i.second->stop = true;
						break;
					}
					currTimerId = 0u;
					i.second->lastTime = GAMEPLAY::GET_GAME_TIMER();
				}
			}
		}
	};
};