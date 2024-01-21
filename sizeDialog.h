#pragma once
#pragma once
#include "wx/dialog.h"
#include "wx/listbox.h"
#include "wx/sizer.h"
#include "wx/spinctrl.h"
#include "wx/stattext.h"
#include "wx/sizer.h"
#include "wx/dialog.h"
class sizeDialog : public wxDialog
{
private:

public:
	wxStaticText* size_text;
	wxSpinCtrl* m_sizeSpin;

public:

	sizeDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(160, 100), long style = wxDEFAULT_DIALOG_STYLE);
	void showDialog();
	~sizeDialog();

};

