#include "MyLogger.hpp"

Logger::Logger(const std::string& filename) {
    if (!filename.empty()) {
        logFile.open(filename, std::ios::app);
        toFile = logFile.is_open();
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::string prefix = getTime() + " [" + levelToString(level) + "] ";

    if (toFile) {
        logFile << prefix << message << std::endl;
    }

}

void Logger::debug(const std::string& msg)  { log(LogLevel::DEBUG, msg); }
void Logger::info(const std::string& msg)   { log(LogLevel::INFO, msg); }
void Logger::warn(const std::string& msg)   { log(LogLevel::WARNING, msg); }
void Logger::error(const std::string& msg)  { log(LogLevel::ERR, msg); }

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
    case LogLevel::DEBUG:   return "DEBUG";
    case LogLevel::INFO:    return "INFO";
    case LogLevel::WARNING: return "WARNING";
    case LogLevel::ERR:   return "ERROR";
    }
    return "UNKNOWN";
}

std::string Logger::getTime() {
    std::time_t now = std::time(nullptr);
    struct tm timeInfo {};

#ifdef _WIN32
    localtime_s(&timeInfo, &now);
#else
    localtime_r(&now, &timeInfo);
#endif

    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeInfo);
    return buf;
}