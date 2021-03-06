// For compilers that support precompilation, includes "wx/wx.h".

#include "widgets/wx_include.h"
#include "widgets/MainWindow.h"

class TestingApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(TestingApp);

bool TestingApp::OnInit()
{
	MainWindow *frame = new MainWindow();
	frame->Show(true);
	return true;
}

