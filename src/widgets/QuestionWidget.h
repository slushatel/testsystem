#ifndef QUESTION_WIDGET_H
#define QUESTION_WIDGET_H

#include "wx_include.h"
#include "model/Test.h"

class QuestionWidget : public wxPanel
{
	Test test;
	int* answers = nullptr;
	int cur_question = 0;

public:
	QuestionWidget(wxWindow* parent);
	void setTestPath(std::string path);
private:
	void showQuestions();
	void OnAnswerSelected(wxCommandEvent& event);
};

#endif
