
#include <string>
#include "model/Test.h"
#include "model/Question.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include "Converter.h"

namespace Converter {
    Test readTest(std::string path)
    {
        // read a JSON file
//        std::ifstream in("E:\\My_documents\\_Sasha\\cpp\\TestSystem\\src\\widgets\\test1.tst");
        std::ifstream in("tests/" + path);
        nlohmann::json j = nlohmann::json::parse(in);
        std::cout << j["name"].get<std::string>();
        Test test;
        test.name = j["name"].get<std::string>();

        for (auto& element : j["questions"]) {
            Question q;
            q.question_text = element["question_text"].get<std::string>();
            for (auto& answer : element["answers"]) {
                q.answers.push_back(answer.get<std::string>());
            }
            q.correct_answer = element["correct_answer"].get<int>();
            test.questions.push_back(q);
        }

        return test;
    }
}
