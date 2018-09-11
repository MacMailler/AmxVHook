#include "log.hpp"

namespace AmxVHook {

	std::shared_ptr<Log> gLog;

	Log::Log(const std::string & path) : logFile(path) {
		init();
	}

	Log::Log(const char * path) : logFile(path) {
		init();
	}

	Log::~Log() {
	#if defined THREADED_LOG
		threadInstance.reset();
	#else
		ofs.close();
	#endif
	}

	void Log::init() {
	#if defined THREADED_LOG
		try {
			if (Fs::exists(logFile))
				Fs::remove(logFile);
		}
		catch (Fs::filesystem_error& err) {
			gLog->log("Cannot remove old log file (What: %s)", err.what());
		}

		threadInstance = std::make_shared<std::thread>(std::bind(&Log::Thread));
	#else
		ofs.open(logFile, std::ios::trunc);
		ofs
			<< "// AmxVHook " << AMXVHOOK_VER << " (build " << __DATE__ << ")" << std::endl
			<< "// (C) MacMailler, 2018" << std::endl;
	#endif
	}

	void Log::log(char * format, ...) {
		va_list args;
		va_start(args, format);

		std::string data;
		String::vformat(format, data, args);

	#if defined THREADED_LOG
	try_lock :
		if (mutex.try_lock()) {
			queue.push(data);
			mutex.unlock();
		}
		else {
			std::this_thread::yield();
			goto try_lock;
		}
	#else
		String::vformat(format, data, args);
		doWrite(logFile, data);
	#endif
		va_end(args);
	}

	void Log::doWrite(std::string & path, std::string & data) {
	#if defined THREADED_LOG
		std::ofstream ofs(path, std::ios::app);
	#endif
		char timeform[16];
		struct tm *timeinfo;
		time_t rawtime;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(timeform, sizeof timeform, "%X", timeinfo);

		ofs << "[" << timeform << "] " << data << std::endl;
	}
#if defined THREADED_LOG
	void Log::doWork() {
		std::string data;

		while (true) {
			mutex.lock();
			if (queue.empty()) {
				mutex.unlock();
				break;
			}
			data = queue.front();
			mutex.unlock();

			doWrite(logFile, data);

		try_lock:
			if (mutex.try_lock()) {
				queue.pop();
				mutex.unlock();
			}
			else {
//				gLog->log("Cannot lock log queue mutex, continuing anyway");
				std::this_thread::yield();
				goto try_lock;
			}

			std::this_thread::yield();
		}
	}

	void Log::Thread() {
		gLog->log("// AmxVHook %s (%s)", AMXVHOOK_VER, __DATE__);
		gLog->log("// (C) MacMailler, 2018");

		while (true) {
			gLog->doWork();

			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
#endif
};