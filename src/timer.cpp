#include "timer.hpp"

namespace AmxVHook {

	extern std::shared_ptr<AmxVHook::Pool> gPool;
	std::shared_ptr<Timer::Pool> gTimer;

	namespace Timer {
		Pool::Pool() {
			ident.reset();
			pool.clear();
		}

		Pool::~Pool() {
			clear();
		}

		cell Pool::add(std::shared_ptr<Timer> & timer) {
			cell id = ident.get();

			pool.insert({ id, std::move(timer) });

			return id;
		}

		bool Pool::drop(cell id) {
			if (!contains(id))
				return false;

			pool[id].reset();
			pool.erase(id);
			ident.remove(id);

			return true;
		}

		bool Pool::stop(cell id, bool stop) {
			if (!contains(id))
				return false;

			pool[id]->stop = stop;

			return true;
		}

		bool Pool::stopped(cell id) {
			if (!contains(id))
				return false;

			return pool[id]->stop;
		}

		bool Pool::contains(cell id) {
			return pool.find(id) == pool.end();
		}

		void Pool::clear() {
			for (auto& i : pool) {
				i.second.reset();
				pool.erase(i.first);
			}

			ident.reset();
		}

		void Pool::clearByAmx(AMX * amx) {
			for (const auto& i : pool) {
				if (i.second->amx == amx) {
					pool.erase(i.first);
					ident.remove(i.first);
				}
			}
		}

		bool Pool::setData(cell id, std::stack<std::variant<cell, std::string>> & params) {
			if (!contains(id))
				return false;
			
			pool[id]->params = std::move(params);

			return true;
		}

		bool Pool::setInterval(cell id, ucell interval) {
			if (!contains(id))
				return false;

			pool[id]->interval = interval;

			return true;
		}

		void Pool::process() {
			for (const auto& i : pool) {
				if (i.second->stop) continue;

				if ((GAMEPLAY::GET_GAME_TIMER() - i.second->lastTime) >= i.second->interval) {
					
					switch (gPool->exec(i.second->amx, i.second->funcname, &i.second->params)) {
					case TIMER_CODE_DROP:
						pool.erase(i.first);
						break;
					
					case TIMER_CODE_PAUSE :
						i.second->stop = true;
						break;
					}
					i.second->lastTime = GAMEPLAY::GET_GAME_TIMER();
				}
			}
		}
	};
};