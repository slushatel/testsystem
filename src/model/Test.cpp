#ifndef TEST_H
#define TEST_H

#include <string>
#include <vector>
#include "Question.cpp"

struct Test {
	std::string name;
	std::vector<Question> questions;
};

#endif