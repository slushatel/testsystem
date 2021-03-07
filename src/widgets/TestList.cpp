#include "wx_include.h"
#include "converter/Converter.h"
#include "helpers/FileReader.h"
#include "TestList.h"
#include "MainWindow.h"

namespace {
	void fillListBox(wxListBox* listBox) {
		auto file_list = FileReader::readFileList("tests");
		for (const auto& file : file_list)
		{
			listBox->Append(file.filename().u8string());
		}
	}
}

TestList::TestList(wxWindow* parent) : wxPanel(parent)
{
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

	listBox = new wxListBox(this, wxID_ANY, wxPoint(-1, -1), wxSize(-1, -1));
	fillListBox(listBox);
	topSizer->Add(listBox, 3, wxEXPAND | wxALL, 10);

	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	wxButton* startButton = new wxButton(this, wxID_ANY, "Start");
	startButton->Bind(wxEVT_BUTTON, &TestList::OnStart, this);
	buttonSizer->Add(startButton, 0, wxALL, 10);

	topSizer->Add(buttonSizer, 0, wxALIGN_CENTER);
	SetSizerAndFit(topSizer);
}

void TestList::OnStart(wxCommandEvent& event)
{
	wxMessageBox("Selected: " + listBox->GetString(listBox->GetSelection()),
		"Selection", wxOK | wxICON_INFORMATION);
}

