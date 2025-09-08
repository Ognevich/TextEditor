#include "FileSystem.hpp"
#include "Logger.hpp"

std::vector<std::string> FileSystem::LoadFromFile(const std::string& filePath)
{
    std::ifstream file(filePath);

    if (checkFileOpen(file)) {
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

    if (checkFileOpen(file)) {
        return;
    }

    for (auto& line : data) {
        file << line << "\n";
    }

    file.close();
}
