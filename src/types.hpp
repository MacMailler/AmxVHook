#pragma once

namespace AmxVHook {
	struct Mod;

	using Callback = std::pair<std::string, int>;
	using ModPool = std::unordered_map<std::string, Mod>;
	using PublicPool = std::unordered_map<AMX*, std::unordered_map<const char*, int>>;
	using NativeList = std::list<AMX_NATIVE_INFO *>;
	using AmxArgs = std::stack<std::variant<cell, std::string>>;

	namespace Fs = std::experimental::filesystem;
};