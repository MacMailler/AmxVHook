#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	class Log : NonCopy {
	private:
		std::string logFile;
#if defined THREADED_LOG
		std::mutex mutex;
		std::shared_ptr<std::thread> threadInstance;
		std::queue<std::string> queue;
#else
		std::ofstream ofs;
#endif
		void init();
		void doWrite(std::string & path, std::string & data);

	public:
		Log(const std::string & path);
		Log(const char * path);
		~Log();

		void log(char * format, ...);
#if defined THREADED_LOG
		void doWork();
		std::thread * getThreadInstance() const {
			return threadInstance.get();
		}

		static void Thread();
#endif
	};
};