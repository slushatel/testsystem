#include "wx_include.h"
#include "converter/Converter.cpp"
#include "helpers/FileReader.cpp"

class TestList : public wxPanel
{
public:
	TestList(wxWindow *parent) : wxPanel(parent)
	{

		wxListBox *listBox = new wxListBox(this, wxID_ANY,
										   wxPoint(-1, -1), wxSize(-1, -1));

		// Test test = Converter::readTest("");
		auto file_list = FileReader::readFileList("tests");
		// listBox->Append(test.name);
		for (const auto &file : file_list)
		{

			listBox->Append(file.filename().u8string());
		}

		// listBox->Append(wxString("2"));
		// listBox->Append(wxString("3"));
		wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
		// Create text ctrl with minimal size 100x60
		topSizer->Add(
			listBox,
			3,		   // make vertically stretchable
			wxEXPAND | // make horizontally stretchable
				wxALL, // and make border all around
			10);	   // set border width to 10

		wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);
		buttonSizer->Add(new wxButton(this, wxID_OK, "Start"),
						 0,		// make horizontally unstretchable
						 wxALL, // make border all around: implicit top alignment
						 10);	// set border width to 10
		buttonSizer->Add(new wxButton(this, wxID_CANCEL, "Cancel"),
						 0,		// make horizontally unstretchable
						 wxALL, // make border all around (implicit top alignment)
						 10);	// set border width to 10
		topSizer->Add(buttonSizer,
					  0,			   // make vertically unstretchable
					  wxALIGN_CENTER); // no border and centre horizontally
		// SetSizer(topSizer);	// use the sizer for layout
		// topSizer->Fit(this);		  // fit the dialog to the contents
		// topSizer->SetSizeHints(this); // set hints to honor min size

		SetSizerAndFit(topSizer);
	}
};