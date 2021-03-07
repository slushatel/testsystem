#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "wx_include.h"
//#include "converter/Converter.cpp"
//#include "helpers/FileReader.cpp"

class TestList : public wxPanel
{
	wxListBox* listBox;
public:
	TestList(wxWindow* parent, wxFrame* frame);
	void OnStart(wxCommandEvent& event);
};

#endif
