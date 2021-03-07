#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include "widgets/wx_include.h"
namespace fs = std::filesystem;

namespace FileReader
{
    std::vector<fs::path> readFileList(std::string path)
    {
        std::vector<fs::path> file_list;
        if (fs::exists(path)) {
            for (const auto& entry : fs::directory_iterator(path, std::filesystem::directory_options::skip_permission_denied))
            {
                file_list.push_back(entry.path());
            }
        }
        else {
            wxMessageBox("Test directory not found",
                "No directory", wxOK | wxICON_ERROR);
        }
        return file_list;
    }
};
