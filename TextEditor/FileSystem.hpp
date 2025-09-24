#define _CRT_SECURE_NO_WARNINGS
#ifndef _FILE_SYSTEM_HPP_
#define _FILE_SYSTEM_HPP_
#include <string>
#include <fstream>
#include <vector>
#include "Config.hpp"

class FileSystem {

    std::string filename;
    std::string filePath;

private:

    template <typename T>
    bool isOpen(T& file);
public:
    FileSystem();

    void initFileSystem(std::string filename);

	std::vector<std::string> LoadFromFile(const std::string & filePath);
	void saveToFile(const std::string& filePath, std::vector<std::string> data);

    bool startFileInitialization(int argc);

    std::string getFilePath();

};

template <typename T>
inline bool FileSystem::isOpen(T& file)
{
    return file.is_open();
}



#endif
