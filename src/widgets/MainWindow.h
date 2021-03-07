#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "wx_include.h"

class MainWindow : public wxFrame
{
public:
	MainWindow();
	void OnExit(wxCommandEvent& event);
private:
	void OnHello(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
};

#endif