#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "wx_include.h"
#include <string>

class TestList : public wxPanel
{
	wxListBox* listBox;
public:
	std::string get_selection();
	TestList(wxWindow* parent, int id_test_selected);
};

#endif
