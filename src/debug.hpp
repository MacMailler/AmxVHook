#pragma once
#include "amxvhook.hpp"

namespace AmxVHook {
	class Debug {
	private:
		std::string logFile;
		std::queue<std::string> logQueue;
		boost::mutex lwrMutex;
		boost::shared_mutex ftrMutex;
		boost::shared_ptr<boost::thread> threadInstance;

	public:
		Debug(std::string file);
		~Debug();

		void log(char *format, ...);
		void process();

		std::string Debug::vprintf(const char *format, va_list args);

		boost::thread *getThreadInstance() const {
			return threadInstance.get();
		}

		static void Thread();
	};
};