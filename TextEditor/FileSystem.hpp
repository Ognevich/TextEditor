#ifndef _FILE_SYSTEM_HPP_
#define _FILE_SYSTEM_HPP_
#include <string>
#include <fstream>
#include <vector>
#include "Logger.hpp"


class FileSystem {

private:

public:

	std::vector<std::string> LoadFromFile(std::string & filePath);
	void saveToFile(std::string& filePath, std::vector<std::string> data);

	template <typename T>
	bool checkFileOpen(T& file);

};

template <typename T>
inline bool FileSystem::checkFileOpen(T& file)
{
    if (!file.is_open()) {
        LOG_ERROR("Cannot open this file");
        return 1;
    }
    else return 0;
}



#endif
