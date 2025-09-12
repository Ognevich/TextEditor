#ifndef _FILE_SYSTEM_HPP_
#define _FILE_SYSTEM_HPP_
#include <string>
#include <fstream>
#include <vector>

class FileSystem {

private:

    template <typename T>
    bool checkFileOpen(T& file);
public:

	std::vector<std::string> LoadFromFile(const std::string & filePath);
	void saveToFile(const std::string& filePath, std::vector<std::string> data);


};

template <typename T>
inline bool FileSystem::checkFileOpen(T& file)
{
    if (!file.is_open()) {
        return 1;
    }
    else return 0;
}



#endif
