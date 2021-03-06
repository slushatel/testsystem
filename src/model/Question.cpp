#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

struct Question {
	std::string question_text;
	std::vector<std::string> answers;
	int correct_answer;
};

#endif