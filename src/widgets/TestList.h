#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "wx_include.h"

class TestList : public wxPanel
{
	wxListBox* listBox;
	void OnStart(wxCommandEvent& event);
public:
	TestList(wxWindow* parent);
};

#endif
