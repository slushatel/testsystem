
#include <string>
#include "model/Test.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include "Converter.h"

namespace Converter {
    Test readTest(std::string path)
    {
        // read a JSON file
        std::ifstream in("E:\\My_documents\\_Sasha\\cpp\\TestSystem\\src\\widgets\\test1.tst");
        nlohmann::json j = nlohmann::json::parse(in);
        // nlohmann::json j;
        // i >> j;
        std::cout << j["name"].get<std::string>();
        Test test;
        test.name = j["name"].get<std::string>();
        return test;
    }
}
