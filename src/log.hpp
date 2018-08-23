#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	struct LogData {
		std::string name;
		std::string data;
	};

	class Log : NonCopy {
	private:
		std::string logFile;
		std::queue<std::string> logQueue;

		std::mutex mutex;
		std::shared_ptr<std::thread> threadInstance;

		void init();

	public:
		Log(const std::string & path);
		Log(const char * path);
		~Log();

		void log(char * format, ...);
		void worker(std::ofstream & out);
		void push_log();

		std::thread *getThreadInstance() const {
			return threadInstance.get();
		}

		static void Thread();
		static void format(const char * format, std::string & out, va_list args);
	};
};