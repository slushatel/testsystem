#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "wx_include.h"

class MainWindow : public wxFrame
{
public:
	MainWindow();
private:
	void OnExit(wxCommandEvent& event);
	void OnHello(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	//wxDECLARE_EVENT_TABLE();
};

#endif