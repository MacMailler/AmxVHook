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
		threadInstance.reset();
	}

	void Log::init() {
		try {
			if (Fs::exists(logFile))
				Fs::remove(logFile);
		}
		catch (Fs::filesystem_error& err) {
			gLog->log("Cannot remove old log file (What: %s)", err.what());
		}

		threadInstance = std::make_shared<std::thread>(std::bind(&Log::Thread));
	}

	void Log::log(char * format, ...) {
		va_list args;
		va_start(args, format);

	try_lock_mutex:
		if (mutex.try_lock()) {
			std::string out;
			Log::format(format, out, args);

			logQueue.push(std::move(out));
			mutex.unlock();
		}
		else {
			std::this_thread::yield();
			goto try_lock_mutex;
		}

		va_end(args);
	}

	void Log::worker(std::ofstream & out) {
		char timeform[16];
		struct tm *timeinfo;
		time_t rawtime;

		std::string data;

		while (true) {
			mutex.lock();
			if (logQueue.empty()) {
				mutex.unlock();

				break;
			}
			data = logQueue.front();
			mutex.unlock();

			time(&rawtime);
			timeinfo = localtime(&rawtime);
			strftime(timeform, sizeof timeform, "%X", timeinfo);

			out.open(logFile, (std::ofstream::out | std::ofstream::app));
			out << "[" << timeform << "] " << data << std::endl;
			out.close();

		try_lock_mutex:
			if (mutex.try_lock()) {
				logQueue.pop();
				mutex.unlock();
			}
			else {
				gLog->log("Cannot lock log queue mutex, continuing anyway");
				std::this_thread::yield();
				goto try_lock_mutex;
			}

			std::this_thread::yield();
		}
	}

	void Log::Thread() {
		assert(gLog->getThreadInstance()->get_id() == std::this_thread::get_id());

		while (true) {
			/*std::ofstream file;
			file.open(".\\test.log", (std::ofstream::out | std::ofstream::app));
			file << "threadInstanse: " << gLog->getThreadInstance()->get_id() << ", this_thread: " << std::this_thread::get_id() << std::endl;

			gLog->worker(file);

			file.close();*/

			std::ofstream out;
			gLog->worker(out);

			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}

	void Log::format(const char * format, std::string & out, va_list args) {
		size_t length = vsnprintf(NULL, NULL, format, args);
		char * buffer = (char *)alloca(++length * sizeof(char));
		vsnprintf(buffer, length, format, args);

		out.reserve(length);
		out.assign(buffer);
	}
};