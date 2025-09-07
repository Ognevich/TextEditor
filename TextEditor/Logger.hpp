#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

enum class LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};


class Logger {
public:



	Logger(const std::string& filename = "");
	~Logger();

	void log(LogLevel level, std::string message);
	void debug(const std::string msg);
	void info(const std::string msg);
	void warning(const std::string msg);
	void error(const std::string msg);

private:
	std::ofstream* logFile;

	std::string levelToString(LogLevel level);

	std::string getTime();

};

#endif
