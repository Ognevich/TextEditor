#include "FileSystem.hpp"

FileSystem::FileSystem()
    : filename(""), filePath("")
{
}

void FileSystem::initFileSystem(std::string filename)
{
    this->filename = filename;
    this->filePath = std::string(FILE_PATH) + "\\" + this->filename;
}

std::vector<std::string> FileSystem::LoadFromFile(const std::string& filePath)
{
    std::ifstream file(filePath);

    if (!isOpen(file)) {
        return {};
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    

    file.close();
    return lines;
}

void FileSystem::saveToFile(const std::string& filePath, std::vector<std::string> data)
{

    std::ofstream file(filePath);

    if (!isOpen(file)) {
        return;
    }

    for (auto& line : data) {
        file << line << "\n";
    }

    file.close();
}

bool FileSystem::startFileInitialization(int argc) {
    if (argc < 2) {
        return false; 
    }

    std::ifstream file(this->filePath);
    if (isOpen(file)) {
        return true;
    }
    else {
        std::ofstream newFile(this->filePath);
        if (!isOpen(newFile)) {
            return false; 
        }
        newFile.close();
        return true; 
    }
}

std::string FileSystem::getFilePath()
{
    return this->filePath;
}

