#include "wx_include.h"

class QuestionWidget : public wxPanel
{
	public:
	QuestionWidget(wxWindow *parent) : wxPanel(parent) {
		// wxPanel *panel = new wxPanel(NULL, wxID_ANY);

		// for (int i = 0; i < 3; i++) {
		// 	wxCheckBox *m_cb = new wxCheckBox(panel, ID_CHECKBOX, wxT("Show title "),
		// 		wxPoint(20, i * 20));
		// 	m_cb->SetValue(true);
		// 	//Connect(ID_CHECKBOX, wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CheckBox::OnToggle));
		// }

		// this->AddChild(panel);

		wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
		// Create text ctrl with minimal size 100x60
		topSizer->Add(
			new wxTextCtrl(this, wxID_ANY, "My text.",
						   wxDefaultPosition, wxSize(100, 60), wxTE_MULTILINE),
			1,		   // make vertically stretchable
			wxEXPAND | // make horizontally stretchable
				wxALL, // and make border all around
			10);	   // set border width to 10

		wxString text = wxT("'Cause sometimes you feel tired,\n\
feel weak, and when you feel weak,\
you feel like you wanna just give up.\n\
But you gotta search within you,\
you gotta find that inner strength\n\
and just pull that shit out of you\
and get that motivation to not give up\n\
and not be a quitter,\
no matter how bad you wanna just fall flat on your face and collapse.");
		wxStaticText *st = new wxStaticText(this, wxID_ANY, text,
											wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTRE | wxTEXT_ALIGNMENT_JUSTIFIED);
		topSizer->Add(st, 0, wxEXPAND | wxALL, 5);
		// topSizer->Add(panel, 0,   	wxEXPAND |	wxALL,			5);

		wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);
		buttonSizer->Add(new wxButton(this, wxID_OK, "OK"),
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
		topSizer->Fit(this);		  // fit the dialog to the contents
		topSizer->SetSizeHints(this); // set hints to honor min size

		SetSizerAndFit(topSizer);
	}
};
