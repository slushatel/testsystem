#include "MainWindow.h"
#include "Questionwidget.h"
#include "TestList.h"
#include <wx/simplebook.h>

enum
{
	ID_TEST_SELECTED = 1,
	ID_Hello = 2,
	ID_CHECKBOX = 100
};

MainWindow::MainWindow()
	: wxFrame(NULL, wxID_ANY, "Hello World")
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
	Bind(wxEVT_MENU, &MainWindow::OnHello, this, ID_Hello);
	Bind(wxEVT_MENU, &MainWindow::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);

	book = new wxSimplebook(this);
	panelTestList = new TestList(book, ID_TEST_SELECTED);
	Bind(wxEVT_BUTTON, &MainWindow::OnTestSelected, this, ID_TEST_SELECTED);
	wxPanel* panel2 = new QuestionWidget(book);
	book->AddPage(panelTestList, "");
	book->AddPage(panel2, "");
	book->SetSelection(0);

	Center();
}
void MainWindow::OnExit(wxCommandEvent& event)
{
	Close(true);
}
void MainWindow::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets Hello World example",
		"About Hello World", wxOK | wxICON_INFORMATION);
}
void MainWindow::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

void MainWindow::OnTestSelected(wxCommandEvent& event)
{
	std::string path = panelTestList->get_selection();
	book->SetSelection(1);
	wxMessageBox("Selected: " + path, "Selection", wxOK | wxICON_INFORMATION);
}

