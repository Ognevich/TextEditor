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
    static Logger& getInstance(const std::string& filename = "") {
        static Logger instance(filename);
        return instance;
    }

    void log(LogLevel level, const std::string& message);
    void debug(const std::string& msg);
    void info(const std::string& msg);
    void warn(const std::string& msg);
    void error(const std::string& msg);

private:
    std::ofstream logFile;
    bool toFile{ false };

    Logger(const std::string& filename = "");
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::string levelToString(LogLevel level);
    std::string getTime();
};


#define LOG_DEBUG(msg) Logger::getInstance().debug(msg)
#define LOG_INFO(msg)  Logger::getInstance().info(msg)
#define LOG_WARN(msg)  Logger::getInstance().warn(msg)
#define LOG_ERROR(msg) Logger::getInstance().error(msg)

#endif