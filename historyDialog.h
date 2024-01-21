#pragma once
#include "wx/dialog.h"
#include "wx/listbox.h"
#include "wx/sizer.h"
class HistoryDialog : public wxDialog
{
private:

protected:


public:
	wxListBox* HistoryList;
	void showDialog();
	void clearDialog();
	HistoryDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(700, 200), long style = wxDEFAULT_DIALOG_STYLE);

	~HistoryDialog();

};
