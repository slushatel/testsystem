#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

namespace FileReader
{
	std::vector<fs::path> readFileList(std::string path);
};

#endif