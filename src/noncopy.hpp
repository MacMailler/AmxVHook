#pragma once

namespace AmxVHook {
	class NonCopy {
	protected:
		constexpr NonCopy() = default;
		~NonCopy() = default;

		NonCopy(const NonCopy&) = delete;
		NonCopy& operator=(const NonCopy&) = delete;
	};
};