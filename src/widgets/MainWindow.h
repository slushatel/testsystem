#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "wx_include.h"
#include <wx/simplebook.h>
#include "TestList.h"
#include "QuestionWidget.h"

class MainWindow : public wxFrame
{
private:
	wxSimplebook* book;
	TestList* panelTestList;
	QuestionWidget* panelQuestions;

	void OnExit(wxCommandEvent& event);
	void OnHello(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnTestSelected(wxCommandEvent& event);
public:
	MainWindow();
};

#endif