#include "Logger.hpp"

Logger::Logger(const std::string& filename)
	: logFile(filename.empty() ? nullptr : new std::ofstream(filename, std::ios::app))
{
}

Logger::~Logger()
{
	if (logFile) {
		logFile->close();
		delete logFile;
	}

}

void Logger::log(LogLevel level, std::string message)
{
	std::string prefix = getTime() + " [" + levelToString(level) + "] ";

	if (logFile && logFile->is_open()) {
		(*logFile) << prefix << message << std::endl;
	}
	else {
		std::cout << prefix << message << std::endl;
	}

}

void Logger::debug(const std::string msg)
{
	log(LogLevel::DEBUG, msg);
}

void Logger::info(const std::string msg)
{
	log(LogLevel::INFO, msg);
}

void Logger::warning(const std::string msg)
{
	log(LogLevel::WARNING, msg);
}

void Logger::error(const std::string msg)
{
	log(LogLevel::ERROR, msg);
}

std::string Logger::levelToString(LogLevel level)
{
	switch (level)
	{
	case LogLevel::DEBUG:	return "DEBUG";
	case LogLevel::INFO:	return "INFO";
	case LogLevel::WARNING:	return "WARNING";
	case LogLevel::ERROR:	return "ERROR";
	}
	return "UNKNOWN";
}

std::string Logger::getTime()
{
	std::time_t now = std::time(nullptr);
	char buf[20];
	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	return buf;
}