#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include "model/Test.cpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include "model/Test.cpp"

class Converter
{
private:
    /* data */
public:
    Converter(/* args */);
    ~Converter();
    static Test readTest(std::string path)
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
};

// Converter::Converter(/* args */)
// {
// }

// Converter::~Converter()
// {
// }

#endif