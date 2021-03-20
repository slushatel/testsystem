#include "QuestionWidget.h"
#include "wx_include.h"
#include "converter/Converter.h"
//#include "model/Test.h"

QuestionWidget::QuestionWidget(wxWindow* parent) : wxPanel(parent) {
	// wxPanel *panel = new wxPanel(NULL, wxID_ANY);

	// for (int i = 0; i < 3; i++) {
	// 	wxCheckBox *m_cb = new wxCheckBox(panel, ID_CHECKBOX, wxT("Show title "),
	// 		wxPoint(20, i * 20));
	// 	m_cb->SetValue(true);
	// 	//Connect(ID_CHECKBOX, wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CheckBox::OnToggle));
	// }



	// this->AddChild(panel);

	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

	wxString text = wxT("Thema");
	wxStaticText* st = new wxStaticText(this, wxID_ANY, text,
		wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTRE | wxTEXT_ALIGNMENT_JUSTIFIED);
	topSizer->Add(st, 0, wxEXPAND | wxALL, 5);
	wxPanel* panel = new wxPanel(this);
	topSizer->Add(panel, 1,	wxEXPAND | wxALL, 5);
	wxString q_text = wxT("text");
	wxStaticText* st_q_text = new wxStaticText(panel, wxID_ANY, q_text,
		wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTRE | wxTEXT_ALIGNMENT_JUSTIFIED);

	wxRadioButton* m_radioBtn1 = new wxRadioButton(panel, 0, wxT("A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
	m_radioBtn1->SetValue(true);
//	panel->Add(m_radioBtn1, 0, wxALL, 5);
	wxRadioButton* m_radioBtn2 = new wxRadioButton(panel, 1, wxT("B"), wxDefaultPosition, wxDefaultSize, 0);
//	panel->Add(m_radioBtn2, 0, wxALL, 5);

	Bind(wxEVT_RADIOBUTTON, &QuestionWidget::OnAnswerSelected, this);
	wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
	panelSizer->Add(st_q_text, 0, wxALL, 5);
	panelSizer->Add(m_radioBtn1, 0, wxALL, 5);
	panelSizer->Add(m_radioBtn2, 0, wxALL, 5);
	panel->SetSizer(panelSizer);

	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	buttonSizer->Add(new wxButton(this, wxID_UP, "Prev"),	0,	wxALL, 	10);
	buttonSizer->Add(new wxButton(this, wxID_DOWN, "Next"),	0,	wxALL, 		10);	
	buttonSizer->AddStretchSpacer();
	buttonSizer->Add(new wxButton(this, wxID_OK, "Finish"), 0, wxALL, 10);
	topSizer->Add(buttonSizer,		0,			 		wxEXPAND); 
// SetSizer(topSizer);	// use the sizer for layout
//	topSizer->Fit(this);		  // fit the dialog to the contents
//	topSizer->SetSizeHints(this); // set hints to honor min size

	SetSizerAndFit(topSizer);
}

void QuestionWidget::setTestPath(std::string path)
{
	test = Converter::readTest(path);
	if (answers != nullptr) {
		delete[] answers;
	}
	answers = new int[test.questions.size()];
	showQuestions();
};


void QuestionWidget::showQuestions() {

};

void QuestionWidget::OnAnswerSelected(wxCommandEvent& event)
{
	auto id = event.GetId();
	answers[cur_question] = id;
};
