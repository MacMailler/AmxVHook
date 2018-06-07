#include "debug.hpp"


namespace AmxVHook {

	boost::shared_ptr<Debug> gDebug;

	Debug::Debug(std::string file) {
		boost::filesystem::path path(file);

		try {
			if (boost::filesystem::exists(path))
				boost::filesystem::remove(path);
		}
		catch (boost::filesystem::filesystem_error& err) {
			gDebug->log("Cannot remove old log file (What: %s)", err.what());
		}

		logFile = file;
		threadInstance = boost::shared_ptr<boost::thread>(new boost::thread(boost::bind(&Debug::Thread)));
	}

	Debug::~Debug() {
		threadInstance->interrupt();
		threadInstance.reset();
	}

	void Debug::log(char *format, ...) {
		va_list args;

		va_start(args, format);

	try_lock_mutex:

		if (lwrMutex.try_lock()) {
			logQueue.push(Debug::vprintf(format, args));
			lwrMutex.unlock();
		}
		else {
			boost::this_thread::yield();
			goto try_lock_mutex;
		}

		va_end(args);
	}

	void Debug::process() {
		char timeform[16];
		struct tm *timeinfo;
		time_t rawtime;

		std::string data;
		std::ofstream file;

		while (true) {
			lwrMutex.lock();

			if (logQueue.empty()) {
				lwrMutex.unlock();

				break;
			}

			data = logQueue.front();
			lwrMutex.unlock();

			time(&rawtime);
			timeinfo = localtime(&rawtime);
			strftime(timeform, sizeof timeform, "%X", timeinfo);

			file.open(logFile, (std::ofstream::out | std::ofstream::app));
			file << "[" << timeform << "] " << data << std::endl;
			file.close();

		try_lock_mutex:

			if (lwrMutex.try_lock()) {
				logQueue.pop();
				lwrMutex.unlock();
			} else {
				gDebug->log("Cannot lock debug queue mutex, continuing anyway");
				boost::this_thread::yield();
				goto try_lock_mutex;
			}

			boost::this_thread::yield();
		}
	}

	void Debug::Thread() {
		assert(gDebug->getThreadInstance()->get_id() == boost::this_thread::get_id());

		while (true) {
			boost::this_thread::disable_interruption di;

			gDebug->process();

			boost::this_thread::restore_interruption re(di);
			boost::this_thread::sleep(boost::posix_time::milliseconds(10));
		}
	}

	std::string Debug::vprintf(const char *format, va_list args) {
		int length = vsnprintf(NULL, NULL, format, args);
		char *chars = new char[++length];

		vsnprintf(chars, length, format, args);
		std::string result(chars);

		delete[] chars;

		return result;
	}
};