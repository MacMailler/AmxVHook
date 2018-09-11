#pragma once

namespace AmxVHook {
	struct Mod;
	struct Publics;

	using ModPool = std::unordered_map<std::string, Mod>;
	using NativeList = std::list<AMX_NATIVE_INFO *>;
	using AmxArgs = std::stack<std::variant<cell, std::string>>;
	using PublicList = std::unordered_map<AMX *, Publics>;

	namespace Fs = std::experimental::filesystem;
};