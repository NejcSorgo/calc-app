#include "SizeDialog.h"
sizeDialog::sizeDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bDialogSizer;
	bDialogSizer = new wxBoxSizer(wxHORIZONTAL);

	size_text = new wxStaticText(this, wxID_ANY, wxT("Izberi velikost:"), wxDefaultPosition, wxDefaultSize, 0);
	size_text->Wrap(-1);
	bDialogSizer->Add(size_text, 0, wxALL, 5);

	m_sizeSpin = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 32, 0);
	m_sizeSpin->SetValue(8);
	bDialogSizer->Add(m_sizeSpin, 0, wxALL, 5);


	this->SetSizer(bDialogSizer);
	this->Layout();

	this->Centre(wxBOTH);
}
void sizeDialog::showDialog()
{
	this->Show();
}
sizeDialog::~sizeDialog()
{
}