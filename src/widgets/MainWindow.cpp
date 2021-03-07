#include "MainWindow.h"
#include "Questionwidget.h"
#include "TestList.h"
#include <wx/simplebook.h>

enum
{
	ID_Hello = 1,
	ID_CHECKBOX = 100
};

MainWindow::MainWindow()
	: wxFrame(NULL, wxID_ANY, "Hello World")
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
					 "Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
	Bind(wxEVT_MENU, &MainWindow::OnHello, this, ID_Hello);
	Bind(wxEVT_MENU, &MainWindow::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);

	wxSimplebook *book = new wxSimplebook(this);
	wxPanel *panel1 = new QuestionWidget(book);
	wxPanel *panel2 = new TestList(book);
	book->ShowNewPage(panel1);
	book->ShowNewPage(panel2);

	Center();
}
void MainWindow::OnExit(wxCommandEvent &event)
{
	Close(true);
}
void MainWindow::OnAbout(wxCommandEvent &event)
{
	wxMessageBox("This is a wxWidgets Hello World example",
				 "About Hello World", wxOK | wxICON_INFORMATION);
}
void MainWindow::OnHello(wxCommandEvent &event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

//wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
//EVT_BUTTON(11111, MainWindow::OnAbout)
//wxEND_EVENT_TABLE()
