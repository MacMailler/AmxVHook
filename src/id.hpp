#pragma once
#include <functional>
#include <queue>
#include <vector>

namespace AmxVHook {
	class Id {
	private:
		uint32_t highest;
		std::priority_queue<uint32_t, std::vector<uint32_t>, std::greater<uint32_t>> removed;

	public:
		Id();

		uint32_t get();
		void remove(uint32_t);
		void reset();
	};
};