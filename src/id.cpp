#include "id.hpp"

namespace AmxVHook {
	Id::Id() {
		highest = 0;
	}

	uint32_t Id::get() {
		uint32_t id = 0;
		if (!removed.empty()) {
			id = removed.top();
			removed.pop();
		}
		else {
			id = ++highest;
		}

		return id;
	}

	void Id::remove(uint32_t id) {
		removed.push(id);
	}

	void Id::reset() {
		highest = 0;
		removed = std::priority_queue<uint32_t, std::vector<uint32_t>, std::greater<uint32_t>>();
	}
};