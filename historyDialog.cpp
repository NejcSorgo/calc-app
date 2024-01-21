#include "historyDialog.h"

HistoryDialog::HistoryDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bDialogSizer;
	bDialogSizer = new wxBoxSizer(wxVERTICAL);

	HistoryList = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	bDialogSizer->Add(HistoryList, 1, wxALL | wxEXPAND, 5);


	this->SetSizer(bDialogSizer);
	this->Layout();

	this->Centre(wxBOTH);
}
void HistoryDialog::showDialog()
{
	this->Show();
}
void HistoryDialog::clearDialog()
{
	this->HistoryList->Clear();
}
HistoryDialog::~HistoryDialog()
{
}