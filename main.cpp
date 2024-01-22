#include "main.h"
wxBEGIN_EVENT_TABLE(main, wxFrame)
wxEND_EVENT_TABLE();
main::main(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetToolTip(wxT("Kalkulator"));

	wxBoxSizer* bSizerframeMain;
	bSizerframeMain = new wxBoxSizer(wxVERTICAL);

	main_notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	m_panel_arithemtic = new wxPanel(main_notebook, PANEL_ARITHMETIC, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel_arithemtic->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	m_panel_arithemtic->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));

	wxBoxSizer* bArithmeticSizer;
	bArithmeticSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* resultSizer;
	resultSizer = new wxBoxSizer(wxHORIZONTAL);

	textInput = new wxTextCtrl(m_panel_arithemtic, TEXT_RESULT, wxEmptyString, wxDefaultPosition, wxSize(-1, 40), wxTE_MULTILINE);
	resultSizer->Add(textInput, 1, wxALL | wxEXPAND, 5);


	bArithmeticSizer->Add(resultSizer, 2, wxALL | wxEXPAND, 0);

	wxGridSizer* numberPadSizer;
	numberPadSizer = new wxGridSizer(6, 5, 0, 0);

	btn_leftBrckt = new wxButton(m_panel_arithemtic, BTN_MISC_LBRACKET, wxT("("), wxDefaultPosition, wxSize(-1, -1), 0);
	numberPadSizer->Add(btn_leftBrckt, 0, wxALL | wxEXPAND, 5);

	btn_rightBrckt = new wxButton(m_panel_arithemtic, BTN_MISC_RBRACKET, wxT(")"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_rightBrckt, 0, wxALL | wxEXPAND, 5);

	btn_modus = new wxButton(m_panel_arithemtic, BTN_OP_MODUS, wxT("%"), wxDefaultPosition, wxDefaultSize, 0);
	btn_modus->SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));
	btn_modus->SetToolTip(wxT("Ostanek"));

	numberPadSizer->Add(btn_modus, 0, wxALL | wxEXPAND, 5);

	btn_backspace = new wxButton(m_panel_arithemtic, BTN_CTRL_BACKSPACE, wxT("⌫"), wxDefaultPosition, wxDefaultSize, 0);
	btn_backspace->SetToolTip(wxT("vračalka"));

	numberPadSizer->Add(btn_backspace, 0, wxALL | wxEXPAND, 5);

	btn_multiply = new wxButton(m_panel_arithemtic, BTN_OP_MULTIPLY, wxT("*"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_multiply, 0, wxALL | wxEXPAND, 5);

	btn_exponent = new wxButton(m_panel_arithemtic, BTN_OP_EXP, wxT("x^y"), wxDefaultPosition, wxDefaultSize, 0);
	btn_exponent->SetToolTip(wxT("Kvadrat"));

	numberPadSizer->Add(btn_exponent, 0, wxALL | wxEXPAND, 5);

	btn_root = new wxButton(m_panel_arithemtic, BTN_OP_ROOT, wxT("√"), wxDefaultPosition, wxDefaultSize, 0);
	btn_root->SetToolTip(wxT("Koren"));

	numberPadSizer->Add(btn_root, 0, wxALL | wxEXPAND, 5);

	m_fill = new wxButton(m_panel_arithemtic, BTN_MISC_DOT, wxT("."), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(m_fill, 0, wxALL | wxEXPAND, 5);

	btn_clear = new wxButton(m_panel_arithemtic, BTN_CTRL_CLEAR, wxT("CE"), wxDefaultPosition, wxDefaultSize, 0);
	btn_clear->SetToolTip(wxT("Počisti ekran"));

	numberPadSizer->Add(btn_clear, 0, wxALL | wxEXPAND, 5);

	btn_divide = new wxButton(m_panel_arithemtic, BTN_OP_DIVIDE, wxT("/"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_divide, 0, wxALL | wxEXPAND, 5);

	btn_num0 = new wxButton(m_panel_arithemtic, BTN_NUM_0, wxT("0"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num0, 0, wxALL | wxEXPAND, 5);

	btn_num1 = new wxButton(m_panel_arithemtic, BTN_NUM_1, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num1, 0, wxALL | wxEXPAND, 5);

	btn_num2 = new wxButton(m_panel_arithemtic, BTN_NUM_2, wxT("2"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num2, 0, wxALL | wxEXPAND, 5);

	btn_num3 = new wxButton(m_panel_arithemtic, BTN_NUM_3, wxT("3"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num3, 0, wxALL | wxEXPAND, 5);

	btn_subtract = new wxButton(m_panel_arithemtic, BTN_OP_SUBSTRACT, wxT("-"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_subtract, 0, wxALL | wxEXPAND, 5);

	btn_num4 = new wxButton(m_panel_arithemtic, BTN_NUM_4, wxT("4"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num4, 0, wxALL | wxEXPAND, 5);

	btn_num5 = new wxButton(m_panel_arithemtic, BTN_NUM_5, wxT("5"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num5, 0, wxALL | wxEXPAND, 5);

	btn_num6 = new wxButton(m_panel_arithemtic, BTN_NUM_6, wxT("6"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num6, 0, wxALL | wxEXPAND, 5);

	btn_num7 = new wxButton(m_panel_arithemtic, BTN_NUM_7, wxT("7"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num7, 0, wxALL | wxEXPAND, 5);

	btn_addition = new wxButton(m_panel_arithemtic, BTN_OP_ADD, wxT("+"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_addition, 0, wxALL | wxEXPAND, 5);

	btn_num8 = new wxButton(m_panel_arithemtic, BTN_NUM_8, wxT("8"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num8, 0, wxALL | wxEXPAND, 5);

	btn_num9 = new wxButton(m_panel_arithemtic, BTN_NUM_9, wxT("9"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_num9, 0, wxALL | wxEXPAND, 5);

	btn_hexA = new wxButton(m_panel_arithemtic, BTN_NUM_HEX_A, wxT("A"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_hexA, 0, wxALL | wxEXPAND, 5);

	btn_hexB = new wxButton(m_panel_arithemtic, BTN_NUM_HEX_B, wxT("B"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_hexB, 0, wxALL | wxEXPAND, 5);

	btn_result = new wxButton(m_panel_arithemtic, BTN_CTRL_RESULT, wxT("="), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_result, 0, wxALL | wxEXPAND, 5);

	btn_hexC = new wxButton(m_panel_arithemtic, BTN_NUM_HEX_C, wxT("C"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_hexC, 0, wxALL | wxEXPAND, 5);

	btn_hexD = new wxButton(m_panel_arithemtic, BTN_NUM_HEX_D, wxT("D"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_hexD, 0, wxALL | wxEXPAND, 5);

	btn_hexE = new wxButton(m_panel_arithemtic, BTN_NUM_HEX_E, wxT("E"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_hexE, 0, wxALL | wxEXPAND, 5);

	btn_hexF = new wxButton(m_panel_arithemtic, BTN_NUM_HEX_F, wxT("F"), wxDefaultPosition, wxDefaultSize, 0);
	numberPadSizer->Add(btn_hexF, 0, wxALL | wxEXPAND, 5);

	bArithmeticSizer->Add(numberPadSizer, 5, wxEXPAND, 0);

	m_panel_arithemtic->SetSizer(bArithmeticSizer);
	m_panel_arithemtic->Layout();
	bArithmeticSizer->Fit(m_panel_arithemtic);
	main_notebook->AddPage(m_panel_arithemtic, wxT("Aritmetika"), false);

	// LOGIC PANEL ////////////////////////////////////////////////////////////////////////////////////

	m_panel_logic = new wxPanel(main_notebook, PANEL_LOGIC, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel_logic->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	wxBoxSizer* bLogicSizer;
	bLogicSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bResultSizer;
	bResultSizer = new wxBoxSizer(wxHORIZONTAL);

	logictextInput = new wxTextCtrl(m_panel_logic, LOGIC_TEXT_RESULT, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	bResultSizer->Add(logictextInput, 1, wxALL | wxEXPAND | wxTE_MULTILINE, 5);
	logictextInput->SetExtraStyle(wxTE_MULTILINE);

	bLogicSizer->Add(bResultSizer, 2, wxEXPAND, 0);

	wxGridSizer* gLogicGateSizer;
	gLogicGateSizer = new wxGridSizer(6, 5, 0, 0);

	btn_logic_AND = new wxButton(m_panel_logic, BTN_LOGIC_GATE_AND, wxT("AND"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_AND, 0, wxALL | wxEXPAND, 5);

	btn_logic_OR = new wxButton(m_panel_logic, BTN_LOGIC_GATE_OR, wxT("OR"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_OR, 0, wxALL | wxEXPAND, 5);

	btn_logic_NOT = new wxButton(m_panel_logic, BTN_LOGIC_GATE_NOT, wxT("NOT"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_NOT, 0, wxALL | wxEXPAND, 5);

	btn_logic_clear = new wxButton(m_panel_logic, BTN_LOGIC_CTRL_CLEAR, wxT("CE"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_clear, 0, wxALL | wxEXPAND, 5);

	btn_logic_backspace = new wxButton(m_panel_logic, BTN_LOGIC_CTRL_BACKSPACE, wxT("⌫"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_backspace, 0, wxALL | wxEXPAND, 5);

	btn_logic_NAND = new wxButton(m_panel_logic, BTN_LOGIC_GATE_NAND, wxT("NAND"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_NAND, 0, wxALL | wxEXPAND, 5);

	btn_logic_NOR = new wxButton(m_panel_logic, BTN_LOGIC_GATE_NOR, wxT("NOR"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_NOR, 0, wxALL | wxEXPAND, 5);

	btn_logic_XOR = new wxButton(m_panel_logic, BTN_LOGIC_GATE_XOR, wxT("XOR"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_XOR, 0, wxALL | wxEXPAND, 5);

	btn_logic_XNOR = new wxButton(m_panel_logic, BTN_LOGIC_GATE_XNOR, wxT("XNOR"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_XNOR, 0, wxALL | wxEXPAND, 5);

	btn_logic_leftBrckt = new wxButton(m_panel_logic, BTN_LOGIC_MISC_LBRACKET, wxT("("), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_leftBrckt, 0, wxALL | wxEXPAND, 5);
	btn_logic_num0 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_0, wxT("0"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num0, 0, wxALL | wxEXPAND, 5);

	btn_logic_num1 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_1, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num1, 0, wxALL | wxEXPAND, 5);

	btn_logic_num2 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_2, wxT("2"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num2, 0, wxALL | wxEXPAND, 5);

	btn_logic_num3 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_3, wxT("3"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num3, 0, wxALL | wxEXPAND, 5);

	btn_logic_rightBrckt = new wxButton(m_panel_logic, BTN_LOGIC_MISC_RBRACKET, wxT(")"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_rightBrckt, 0, wxALL | wxEXPAND, 5);

	btn_logic_num4 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_4, wxT("4"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num4, 0, wxALL | wxEXPAND, 5);



	btn_logic_num5 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_5, wxT("5"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num5, 0, wxALL | wxEXPAND, 5);

	btn_logic_num6 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_6, wxT("6"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num6, 0, wxALL | wxEXPAND, 5);

	btn_logic_num7 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_7, wxT("7"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num7, 0, wxALL | wxEXPAND, 5);

	btn_logic_result = new wxButton(m_panel_logic, BTN_LOGIC_CTRL_RESULT, wxT("="), wxDefaultPosition, wxDefaultSize, 0);
	btn_logic_result->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	gLogicGateSizer->Add(btn_logic_result, 0, wxALL | wxEXPAND, 5);
	btn_logic_num8 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_8, wxT("8"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num8, 0, wxALL | wxEXPAND, 5);





	btn_logic_num9 = new wxButton(m_panel_logic, BTN_LOGIC_NUM_9, wxT("9"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num9, 0, wxALL | wxEXPAND, 5);



	btn_logic_num_hexA = new wxButton(m_panel_logic, BTN_LOGIC_NUM_HEX_A, wxT("A"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num_hexA, 0, wxALL | wxEXPAND, 5);

	btn_logic_num_hexB = new wxButton(m_panel_logic, BTN_LOGIC_NUM_HEX_B, wxT("B"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num_hexB, 0, wxALL | wxEXPAND, 5);

	btn_logic_num_hexC = new wxButton(m_panel_logic, BTN_LOGIC_NUM_HEX_C, wxT("C"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num_hexC, 0, wxALL | wxEXPAND, 5);

	btn_logic_num_hexD = new wxButton(m_panel_logic, BTN_LOGIC_NUM_HEX_D, wxT("D"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num_hexD, 0, wxALL | wxEXPAND, 5);

	btn_logic_num_hexE = new wxButton(m_panel_logic, BTN_LOGIC_NUM_HEX_E, wxT("E"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num_hexE, 0, wxALL | wxEXPAND, 5);

	btn_logic_num_hexF = new wxButton(m_panel_logic, BTN_LOGIC_NUM_HEX_F, wxT("F"), wxDefaultPosition, wxDefaultSize, 0);
	gLogicGateSizer->Add(btn_logic_num_hexF, 0, wxALL | wxEXPAND, 5);


	bLogicSizer->Add(gLogicGateSizer, 5, wxEXPAND, 1);


	m_panel_logic->SetSizer(bLogicSizer);
	m_panel_logic->Layout();
	bLogicSizer->Fit(m_panel_logic);
	main_notebook->AddPage(m_panel_logic, wxT("Logična vrata"), true);

	bSizerframeMain->Add(main_notebook, 1, wxEXPAND | wxALL, 0);


	this->SetSizer(bSizerframeMain);
	this->Layout();
	m_statusBar = this->CreateStatusBar(2, wxSTB_SIZEGRIP, STATUS_BAR);
	m_statusBar->DragAcceptFiles(true);

	m_calcmenu = new wxMenuBar(0);
	m_file = new wxMenu();
	wxMenuItem* mi_Import;
	mi_Import = new wxMenuItem(m_file, M_FILE_IMPORT, wxString(wxT("Uvozi")), wxEmptyString, wxITEM_NORMAL);
	m_file->Append(mi_Import);

	wxMenuItem* mi_Export;
	mi_Export = new wxMenuItem(m_file, M_FILE_EXPORT, wxString(wxT("Izvozi")), wxEmptyString, wxITEM_NORMAL);
	m_file->Append(mi_Export);

	m_calcmenu->Append(m_file, wxT("Datoteka"));

	m_numberSystem = new wxMenu();
	mi_Decimal = new wxMenuItem(m_numberSystem, M_NUMSYS_DEC, wxString(wxT("Decimalni")), wxEmptyString, wxITEM_RADIO);
	m_numberSystem->Append(mi_Decimal);
	mi_Decimal->Check(true);

	mi_Binary = new wxMenuItem(m_numberSystem, M_NUMSYS_BIN, wxString(wxT("Binarni")), wxEmptyString, wxITEM_RADIO);
	m_numberSystem->Append(mi_Binary);

	wxMenuItem* mi_Octal;
	mi_Octal = new wxMenuItem(m_numberSystem, M_NUMSYS_OCT, wxString(wxT("Osmiški")), wxEmptyString, wxITEM_RADIO);
	m_numberSystem->Append(mi_Octal);

	wxMenuItem* mi_Hexadecimal;
	mi_Hexadecimal = new wxMenuItem(m_numberSystem, M_NUMSYS_HEX, wxString(wxT("Šestnajstiški")), wxEmptyString, wxITEM_RADIO);
	m_numberSystem->Append(mi_Hexadecimal);

	m_calcmenu->Append(m_numberSystem, wxT("Številski sistem"));

	m_history = new wxMenu();
	wxMenuItem* mi_openHistory;
	mi_openHistory = new wxMenuItem(m_history, M_HISTORY_OPEN, wxString(wxT("Preglej zgodovino")), wxEmptyString, wxITEM_NORMAL);
	m_history->Append(mi_openHistory);
	Bind(wxEVT_MENU, &main::handleShowHistory, this, M_HISTORY_OPEN);

	wxMenuItem* mi_clearHistory;
	mi_clearHistory = new wxMenuItem(m_history, M_HISTORY_CLEAR, wxString(wxT("Počisti zgodovino")), wxEmptyString, wxITEM_NORMAL);
	m_history->Append(mi_clearHistory);

	m_calcmenu->Append(m_history, wxT("Zgodovina"));

	m_size = new wxMenu();
	wxMenuItem* mi_size;
	mi_size = new wxMenuItem(m_size, M_SIZE_OPEN, wxString(wxT("Spremeni velikost")), wxEmptyString, wxITEM_NORMAL);
	m_size->Append(mi_size);

	m_calcmenu->Append(m_size, wxT("Velikost"));

	this->SetMenuBar(m_calcmenu);
	history_dialog = new HistoryDialog(this, wxID_ANY, "Zgodovina");
	size_dialog = new sizeDialog(this, wxID_ANY, "Velikost");
	logic_parser = new logicParser();
	arithmetic_parser = new arithmeticParser();
	//file_dialog = new wxFileDialog(this);
	this->Centre(wxBOTH);
	// menu binds;
	Bind(wxEVT_MENU, &main::handleShowHistory, this, M_HISTORY_OPEN);
	Bind(wxEVT_MENU, &main::handleClearHistory, this, M_HISTORY_CLEAR);
	Bind(wxEVT_MENU, &main::handleSize, this, M_SIZE_OPEN);
	Bind(wxEVT_MENU, &main::handleFileImport, this, M_FILE_IMPORT);
	Bind(wxEVT_MENU, &main::handleNumberSystemChange, this, M_NUMSYS_BIN);
	Bind(wxEVT_MENU, &main::handleNumberSystemChange, this, M_NUMSYS_DEC);
	Bind(wxEVT_MENU, &main::handleNumberSystemChange, this, M_NUMSYS_OCT);
	Bind(wxEVT_MENU, &main::handleNumberSystemChange, this, M_NUMSYS_HEX);
	// arithmetic binds
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_0);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_1);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_2);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_3);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_4);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_5);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_6);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_7);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_8);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_9);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_HEX_A);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_HEX_B);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_HEX_C);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_HEX_D);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_HEX_E);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_NUM_HEX_F);
	Bind(wxEVT_BUTTON, &main::handleOperations, this, BTN_OP_ADD);
	Bind(wxEVT_BUTTON, &main::handleOperations, this, BTN_OP_SUBSTRACT);
	Bind(wxEVT_BUTTON, &main::handleOperations, this, BTN_OP_MULTIPLY);
	Bind(wxEVT_BUTTON, &main::handleOperations, this, BTN_OP_DIVIDE);
	Bind(wxEVT_BUTTON, &main::handleOperations, this, BTN_OP_MODUS);
	Bind(wxEVT_BUTTON, &main::handleOperations, this, BTN_MISC_LBRACKET);
	Bind(wxEVT_BUTTON, &main::handleOperations, this, BTN_MISC_RBRACKET);
	Bind(wxEVT_BUTTON, &main::handleNumButtons, this, BTN_MISC_DOT);
	Bind(wxEVT_BUTTON, &main::handleBackspace, this, BTN_CTRL_BACKSPACE);
	Bind(wxEVT_BUTTON, &main::handleClear, this, BTN_CTRL_CLEAR);
	Bind(wxEVT_BUTTON, &main::handleFunction, this, BTN_OP_ROOT);
	Bind(wxEVT_BUTTON, &main::handleFunction, this, BTN_OP_EXP);
	Bind(wxEVT_BUTTON, &main::handleResult, this, BTN_CTRL_RESULT);

	// logic binds
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_0);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_1);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_2);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_3);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_4);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_5);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_6);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_7);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_8);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_9);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_HEX_A);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_HEX_B);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_HEX_C);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_HEX_D);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_HEX_E);
	Bind(wxEVT_BUTTON, &main::handleNumLogicButtons, this, BTN_LOGIC_NUM_HEX_F);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_GATE_AND);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_GATE_OR);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_GATE_NOT);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_GATE_NAND);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_GATE_NOR);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_GATE_XOR);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_GATE_XNOR);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_MISC_LBRACKET);
	Bind(wxEVT_BUTTON, &main::handleLogicOperations, this, BTN_LOGIC_MISC_RBRACKET);
	Bind(wxEVT_BUTTON, &main::handleLogicBackspace, this, BTN_LOGIC_CTRL_BACKSPACE);
	Bind(wxEVT_BUTTON, &main::handleLogicClear, this, BTN_LOGIC_CTRL_CLEAR);
	Bind(wxEVT_BUTTON, &main::handleLogicResult, this, BTN_LOGIC_CTRL_RESULT);

}

void main::handleNumberSystemChange(wxCommandEvent& event) // za marka
{
	std::string stringInputText = std::string(textInput->GetValue().mb_str());
	std::string stringLogicInputText = std::string(logictextInput->GetValue().mb_str());
	if (stringInputText.empty())
	{
		stringInputText = "0";
	}
	if (stringLogicInputText.empty())
	{
		stringLogicInputText = "0";
	}
	if (event.GetId() == M_NUMSYS_DEC) // decimal
	{
		FindWindowById(BTN_NUM_1)->Enable();
		FindWindowById(BTN_NUM_2)->Enable();
		FindWindowById(BTN_NUM_3)->Enable();
		FindWindowById(BTN_NUM_4)->Enable();
		FindWindowById(BTN_NUM_5)->Enable();
		FindWindowById(BTN_NUM_6)->Enable();
		FindWindowById(BTN_NUM_7)->Enable();
		FindWindowById(BTN_NUM_8)->Enable();
		FindWindowById(BTN_NUM_9)->Enable();
		FindWindowById(BTN_NUM_HEX_A)->Disable();
		FindWindowById(BTN_NUM_HEX_B)->Disable();
		FindWindowById(BTN_NUM_HEX_C)->Disable();
		FindWindowById(BTN_NUM_HEX_D)->Disable();
		FindWindowById(BTN_NUM_HEX_E)->Disable();
		FindWindowById(BTN_NUM_HEX_F)->Disable();
		FindWindowById(BTN_LOGIC_NUM_0)->Enable();
		FindWindowById(BTN_LOGIC_NUM_1)->Enable();
		FindWindowById(BTN_LOGIC_NUM_2)->Enable();
		FindWindowById(BTN_LOGIC_NUM_3)->Enable();
		FindWindowById(BTN_LOGIC_NUM_4)->Enable();
		FindWindowById(BTN_LOGIC_NUM_5)->Enable();
		FindWindowById(BTN_LOGIC_NUM_6)->Enable();
		FindWindowById(BTN_LOGIC_NUM_7)->Enable();
		FindWindowById(BTN_LOGIC_NUM_8)->Enable();
		FindWindowById(BTN_LOGIC_NUM_9)->Enable();
		FindWindowById(BTN_LOGIC_NUM_0)->Enable();
		FindWindowById(BTN_LOGIC_NUM_HEX_A)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_B)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_C)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_D)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_E)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_F)->Disable();
		switch (this->currentNumSystem)
		{
		case M_NUMSYS_BIN:
			textInput->SetValue(wxString(this->numCnvrt->BinaryToDecimal(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->BinaryToDecimal(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		case M_NUMSYS_HEX:
			textInput->SetValue(wxString(this->numCnvrt->HexToDecimal(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->HexToDecimal(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		case M_NUMSYS_OCT:
			textInput->SetValue(wxString(this->numCnvrt->OctalToDecimal(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->OctalToDecimal(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		default:
			break;
		}

	}
	else if (event.GetId() == M_NUMSYS_BIN) // binary
	{
		FindWindowById(BTN_NUM_0)->Enable();
		FindWindowById(BTN_NUM_1)->Enable();
		FindWindowById(BTN_NUM_2)->Disable();
		FindWindowById(BTN_NUM_3)->Disable();
		FindWindowById(BTN_NUM_4)->Disable();
		FindWindowById(BTN_NUM_5)->Disable();
		FindWindowById(BTN_NUM_6)->Disable();
		FindWindowById(BTN_NUM_7)->Disable();
		FindWindowById(BTN_NUM_8)->Disable();
		FindWindowById(BTN_NUM_9)->Disable();
		FindWindowById(BTN_NUM_HEX_A)->Disable();
		FindWindowById(BTN_NUM_HEX_B)->Disable();
		FindWindowById(BTN_NUM_HEX_C)->Disable();
		FindWindowById(BTN_NUM_HEX_D)->Disable();
		FindWindowById(BTN_NUM_HEX_E)->Disable();
		FindWindowById(BTN_NUM_HEX_F)->Disable();
		FindWindowById(BTN_LOGIC_NUM_0)->Enable();
		FindWindowById(BTN_LOGIC_NUM_1)->Enable();
		FindWindowById(BTN_LOGIC_NUM_2)->Disable();
		FindWindowById(BTN_LOGIC_NUM_3)->Disable();
		FindWindowById(BTN_LOGIC_NUM_4)->Disable();
		FindWindowById(BTN_LOGIC_NUM_5)->Disable();
		FindWindowById(BTN_LOGIC_NUM_6)->Disable();
		FindWindowById(BTN_LOGIC_NUM_7)->Disable();
		FindWindowById(BTN_LOGIC_NUM_8)->Disable();
		FindWindowById(BTN_LOGIC_NUM_9)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_A)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_B)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_C)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_D)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_E)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_F)->Disable();
		switch (this->currentNumSystem)
		{
		case M_NUMSYS_DEC:
			textInput->SetValue(wxString(this->numCnvrt->DecimalToBinary(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->DecimalToBinary(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		case M_NUMSYS_HEX:
			textInput->SetValue(wxString(this->numCnvrt->HexToBinary(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->HexToBinary(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		case M_NUMSYS_OCT:
			textInput->SetValue(wxString(this->numCnvrt->OctalToBinary(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->OctalToBinary(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		default:
			break;
		}

	}
	else if (event.GetId() == M_NUMSYS_HEX) // hex
	{
		FindWindowById(BTN_NUM_0)->Enable();
		FindWindowById(BTN_NUM_1)->Enable();
		FindWindowById(BTN_NUM_2)->Enable();
		FindWindowById(BTN_NUM_3)->Enable();
		FindWindowById(BTN_NUM_4)->Enable();
		FindWindowById(BTN_NUM_5)->Enable();
		FindWindowById(BTN_NUM_6)->Enable();
		FindWindowById(BTN_NUM_7)->Enable();
		FindWindowById(BTN_NUM_8)->Enable();
		FindWindowById(BTN_NUM_9)->Enable();
		FindWindowById(BTN_NUM_HEX_A)->Enable();
		FindWindowById(BTN_NUM_HEX_B)->Enable();
		FindWindowById(BTN_NUM_HEX_C)->Enable();
		FindWindowById(BTN_NUM_HEX_D)->Enable();
		FindWindowById(BTN_NUM_HEX_E)->Enable();
		FindWindowById(BTN_NUM_HEX_F)->Enable();
		FindWindowById(BTN_LOGIC_NUM_0)->Enable();
		FindWindowById(BTN_LOGIC_NUM_1)->Enable();
		FindWindowById(BTN_LOGIC_NUM_2)->Enable();
		FindWindowById(BTN_LOGIC_NUM_3)->Enable();
		FindWindowById(BTN_LOGIC_NUM_4)->Enable();
		FindWindowById(BTN_LOGIC_NUM_5)->Enable();
		FindWindowById(BTN_LOGIC_NUM_6)->Enable();
		FindWindowById(BTN_LOGIC_NUM_7)->Enable();
		FindWindowById(BTN_LOGIC_NUM_8)->Enable();
		FindWindowById(BTN_LOGIC_NUM_9)->Enable();
		FindWindowById(BTN_LOGIC_NUM_HEX_A)->Enable();
		FindWindowById(BTN_LOGIC_NUM_HEX_B)->Enable();
		FindWindowById(BTN_LOGIC_NUM_HEX_C)->Enable();
		FindWindowById(BTN_LOGIC_NUM_HEX_D)->Enable();
		FindWindowById(BTN_LOGIC_NUM_HEX_E)->Enable();
		FindWindowById(BTN_LOGIC_NUM_HEX_F)->Enable();
		switch (this->currentNumSystem)
		{
		case M_NUMSYS_DEC:
			textInput->SetValue(wxString(this->numCnvrt->DecimalToHex(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->DecimalToHex(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		case M_NUMSYS_BIN:
			textInput->SetValue(wxString(this->numCnvrt->BinaryToHexadecimal(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->BinaryToHexadecimal(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		case M_NUMSYS_OCT:
			textInput->SetValue(wxString(this->numCnvrt->OctalToHexadecimal(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->OctalToHexadecimal(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		default:
			break;
		}
	}
	else // octal
	{
		FindWindowById(BTN_NUM_0)->Enable();
		FindWindowById(BTN_NUM_1)->Enable();
		FindWindowById(BTN_NUM_2)->Enable();
		FindWindowById(BTN_NUM_3)->Enable();
		FindWindowById(BTN_NUM_4)->Enable();
		FindWindowById(BTN_NUM_5)->Enable();
		FindWindowById(BTN_NUM_6)->Enable();
		FindWindowById(BTN_NUM_7)->Enable();
		FindWindowById(BTN_NUM_8)->Disable();
		FindWindowById(BTN_NUM_9)->Disable();
		FindWindowById(BTN_NUM_HEX_A)->Disable();
		FindWindowById(BTN_NUM_HEX_B)->Disable();
		FindWindowById(BTN_NUM_HEX_C)->Disable();
		FindWindowById(BTN_NUM_HEX_D)->Disable();
		FindWindowById(BTN_NUM_HEX_E)->Disable();
		FindWindowById(BTN_NUM_HEX_F)->Disable();
		FindWindowById(BTN_LOGIC_NUM_0)->Enable();
		FindWindowById(BTN_LOGIC_NUM_1)->Enable();
		FindWindowById(BTN_LOGIC_NUM_2)->Enable();
		FindWindowById(BTN_LOGIC_NUM_3)->Enable();
		FindWindowById(BTN_LOGIC_NUM_4)->Enable();
		FindWindowById(BTN_LOGIC_NUM_5)->Enable();
		FindWindowById(BTN_LOGIC_NUM_6)->Enable();
		FindWindowById(BTN_LOGIC_NUM_7)->Enable();
		FindWindowById(BTN_LOGIC_NUM_8)->Disable();
		FindWindowById(BTN_LOGIC_NUM_9)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_A)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_B)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_C)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_D)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_E)->Disable();
		FindWindowById(BTN_LOGIC_NUM_HEX_F)->Disable();
		switch (this->currentNumSystem)
		{
		case M_NUMSYS_DEC:
			textInput->SetValue(wxString(this->numCnvrt->DecimalToOctal(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->DecimalToOctal(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		case M_NUMSYS_HEX:
			textInput->SetValue(wxString(this->numCnvrt->HexToOctal(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->HexToOctal(stringLogicInputText).c_str(), wxConvUTF8));
			break;
		case M_NUMSYS_BIN:
			textInput->SetValue(wxString(this->numCnvrt->BinaryToOctal(stringInputText).c_str(), wxConvUTF8));
			logictextInput->SetValue(wxString(this->numCnvrt->BinaryToOctal(stringLogicInputText).c_str(), wxConvUTF8));

			break;
		default:
			break;
		}
	}
	this->currentNumSystem = event.GetId();
}
void main::handleNumButtons(wxCommandEvent& event)
{
	textInput->AppendText(FindWindowById(event.GetId())->GetLabel());
	event.Skip();
}
void main::handleNumLogicButtons(wxCommandEvent& event)
{
	logictextInput->AppendText(FindWindowById(event.GetId())->GetLabel());
	event.Skip();
}
void main::handleLogicOperations(wxCommandEvent& event) {
	logictextInput->AppendText(" " + FindWindowById(event.GetId())->GetLabel() + " ");
	event.Skip();
}
void main::handleLogicBackspace(wxCommandEvent& event) {

	wxString txt = logictextInput->GetValue();
	if (txt.empty())
	{
		return;
		event.Skip();
	}

	txt.erase(txt.Length() - 1);
	logictextInput->SetValue(txt);
	event.Skip();
}
void main::handleLogicResult(wxCommandEvent& event) {
	std::string stringInputText = std::string(logictextInput->GetValue().mb_str());
	if (stringInputText.empty())
	{
		return;
	}
	switch (this->currentNumSystem)
	{
	case M_NUMSYS_DEC:
		stringInputText = numCnvrt->DecimalToBinary(stringInputText);
		break;
	case M_NUMSYS_HEX:
		stringInputText = numCnvrt->HexToBinary(stringInputText);
		break;
	case M_NUMSYS_OCT:
		stringInputText = numCnvrt->OctalToBinary(stringInputText);
		break;

	default:
		break;
	}
	std::string filtered_string = logic_parser->parseNOTgates(stringInputText, size_dialog->m_sizeSpin->GetValue());
	std::vector<bool> result = logic_parser->parseLogicGates(filtered_string, size_dialog->m_sizeSpin->GetValue());
	history_dialog->HistoryList->Append(wxString(stringInputText + " = " + this->logic_parser->booleanToString(result)));
	this->currentNumSystem = M_NUMSYS_BIN;
	mi_Binary->Check();
	//wxMenuItem* bruh = reinterpret_cast<wxMenuItem>(FindWindowById(M_NUMSYS_BIN));

	logictextInput->SetValue(wxString(this->logic_parser->booleanToString(result)));
}
void main::handleOperations(wxCommandEvent& event) {

	textInput->AppendText(" " + FindWindowById(event.GetId())->GetLabel() + " ");
	event.Skip();
}
void main::handleBackspace(wxCommandEvent& event) {

	wxString txt = textInput->GetValue();
	if (txt.empty())
	{
		return;
		event.Skip();
	}

	txt.erase(txt.Length() - 1);
	textInput->SetValue(txt);
	event.Skip();
}
void main::handleClear(wxCommandEvent& event) {

	textInput->SetValue("");
	event.Skip();
}
void main::handleLogicClear(wxCommandEvent& event) {

	logictextInput->SetValue("");
	event.Skip();
}
void main::handleShowHistory(wxCommandEvent& event)
{
	history_dialog->showDialog();
	event.Skip();
}
void main::handleClearHistory(wxCommandEvent& event)
{
	history_dialog->HistoryList->Clear();
	event.Skip();
}
void main::handleFunction(wxCommandEvent& event)
{
	switch (event.GetId())
	{
	case BTN_OP_EXP:
		textInput->AppendText("pow( , )");
		break;
	case BTN_OP_ROOT:
		textInput->AppendText("sqrt( )");
		break;
	default:
		break;
	}
	history_dialog->clearDialog();
	event.Skip();
}
void main::handleFileImport(wxCommandEvent& event)
{

	wxFileDialog
		openFileDialog(this, _("Izberi datoteko"), "", "",
			"TXT files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea...

	// proceed loading the file chosen by the user;
	// this can be done with e.g. wxWidgets input streams:
	wxFileInputStream input(openFileDialog.GetPath());
	wxTextInputStream text(input, wxT("\x09"), wxConvUTF8);
	if (main_notebook->GetSelection() == 1) // (logicna vrata)
	{
		while (input.IsOk() && !input.Eof())
		{
			std::string stringInputText = std::string(text.ReadLine());
			if (stringInputText.empty())
			{
				continue;
			}
			switch (this->currentNumSystem)
			{
			case M_NUMSYS_DEC:
				stringInputText = numCnvrt->DecimalToBinary(stringInputText);
				break;
			case M_NUMSYS_HEX:
				stringInputText = numCnvrt->HexToBinary(stringInputText);
				break;
			case M_NUMSYS_OCT:
				stringInputText = numCnvrt->OctalToBinary(stringInputText);
				break;

			default:
				break;
			}
			std::string filtered_string = logic_parser->parseNOTgates(stringInputText, size_dialog->m_sizeSpin->GetValue());
			std::vector<bool> result = logic_parser->parseLogicGates(filtered_string, size_dialog->m_sizeSpin->GetValue());
			history_dialog->HistoryList->Append(wxString(stringInputText + " = " + this->logic_parser->booleanToString(result)));
			// do something with the string
		}

		this->currentNumSystem = M_NUMSYS_BIN;
	}
	if (main_notebook->GetSelection() == 0) // (aritmetika)
	{
		while (input.IsOk() && !input.Eof())
		{
			std::string stringInputText = std::string(text.ReadLine());
			if (stringInputText.empty())
			{
				continue;
			}
			switch (this->currentNumSystem)
			{
			case M_NUMSYS_DEC:
				stringInputText = numCnvrt->DecimalToBinary(stringInputText);
				break;
			case M_NUMSYS_HEX:
				stringInputText = numCnvrt->HexToBinary(stringInputText);
				break;
			case M_NUMSYS_OCT:
				stringInputText = numCnvrt->OctalToBinary(stringInputText);
				break;

			default:
				break;
			}
			std::string filtered_string = logic_parser->parseNOTgates(stringInputText, size_dialog->m_sizeSpin->GetValue());
			std::vector<bool> result = logic_parser->parseLogicGates(filtered_string, size_dialog->m_sizeSpin->GetValue());
			history_dialog->HistoryList->Append(wxString(stringInputText + " = " + this->logic_parser->booleanToString(result)));
			// do something with the string
		}

		this->currentNumSystem = M_NUMSYS_BIN;
	}
}
void main::handleResult(wxCommandEvent& event) {
	std::string stringInputText = std::string(textInput->GetValue().mb_str());
	if (stringInputText.empty())
	{
		return;
	}
	switch (this->currentNumSystem)
	{
	case M_NUMSYS_BIN:
		stringInputText = numCnvrt->BinaryToDecimal(stringInputText);
		break;
	case M_NUMSYS_HEX:
		stringInputText = numCnvrt->HexToDecimal(stringInputText);
		break;
	case M_NUMSYS_OCT:
		stringInputText = numCnvrt->OctalToDecimal(stringInputText);
		break;

	default:
		break;
	}
	//std::string filtered_string = logic_parser->parseNOTgates(stringInputText, size_dialog->m_sizeSpin->GetValue());
	int result = arithmetic_parser->izracunajRezultat(stringInputText);
	history_dialog->HistoryList->Append(wxString(stringInputText + " = " + std::to_string(result)));
	this->currentNumSystem = M_NUMSYS_BIN;
	mi_Decimal->Check();
	//wxMenuItem* bruh = reinterpret_cast<wxMenuItem>(FindWindowById(M_NUMSYS_BIN));

	textInput->SetValue(wxString(std::to_string(result)));
}

void main::handleSize(wxCommandEvent& event) {
	size_dialog->showDialog();
	event.Skip();
}
main::~main()
{
	delete history_dialog;
	delete size_dialog;
	delete logic_parser;
}

