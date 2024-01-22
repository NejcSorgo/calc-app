#pragma once
#include <wx/wx.h>
#include <wx/txtstrm.h>
#include <wx/notebook.h>
#include <wx/filedlg.h>
#include <wx/stream.h>
#include <wx/wfstream.h>

#include <iostream>
#include <string>

#include "historyDialog.h"
#include "sizeDialog.h"
#include "logicParser.h"
#include "numConverter.h"
#include "arithmeticParser.h"

#define PANEL_ARITHMETIC 1000
#define TEXT_RESULT 1001
#define BTN_MISC_LBRACKET 1002
#define BTN_MISC_RBRACKET 1003
#define BTN_OP_MODUS 1004
#define BTN_CTRL_BACKSPACE 1005
#define BTN_OP_MULTIPLY 1006
#define BTN_OP_EXP 1007
#define BTN_OP_ROOT 1008
#define BTN_CTRL_CLEAR 1009
#define BTN_OP_DIVIDE 1010
#define BTN_NUM_1 1011
#define BTN_NUM_2 1012
#define BTN_NUM_3 1013
#define BTN_NUM_4 1014
#define BTN_OP_SUBSTRACT 1015
#define BTN_NUM_5 1016
#define BTN_NUM_6 1017
#define BTN_NUM_7 1018
#define BTN_NUM_8 1019
#define BTN_OP_ADD 1020
#define BTN_NUM_9 1021
#define BTN_NUM_0 1022
#define BTN_NUM_HEX_A 1023
#define BTN_NUM_HEX_B 1024
#define BTN_CTRL_RESULT 1025
#define BTN_NUM_HEX_C 1026
#define BTN_NUM_HEX_D 1027
#define BTN_NUM_HEX_E 1028
#define BTN_NUM_HEX_F 1029
#define PANEL_LOGIC 1030
#define LOGIC_TEXT_RESULT 1031
#define BTN_LOGIC_GATE_AND 1032
#define BTN_LOGIC_GATE_OR 1033
#define BTN_LOGIC_CTRL_CLEAR 1034
#define BTN_LOGIC_CTRL_BACKSPACE 1035
#define BTN_LOGIC_GATE_NAND 1036
#define BTN_LOGIC_GATE_NOR 1037
#define BTN_LOGIC_GATE_XOR 1038
#define BTN_LOGIC_GATE_XNOR 1039
#define BTN_LOGIC_MISC_LBRACKET 1040
#define BTN_LOGIC_NUM_1 1041
#define BTN_LOGIC_NUM_2 1042
#define BTN_LOGIC_NUM_3 1043
#define BTN_LOGIC_NUM_4 1044
#define BTN_LOGIC_MISC_RBRACKET 1045
#define BTN_LOGIC_NUM_5 1046
#define BTN_LOGIC_NUM_6 1047
#define BTN_LOGIC_NUM_7 1048
#define BTN_LOGIC_NUM_8 1049
#define BTN_LOGIC_CTRL_RESULT 1050
#define BTN_LOGIC_NUM_9 1051
#define BTN_LOGIC_NUM_0 1052
#define BTN_LOGIC_NUM_HEX_A 1053
#define BTN_LOGIC_NUM_HEX_B 1054
#define BTN_LOGIC_NUM_HEX_C 1055
#define BTN_LOGIC_NUM_HEX_D 1056
#define BTN_LOGIC_NUM_HEX_E 1057
#define BTN_LOGIC_NUM_HEX_F 1058
#define STATUS_BAR 1059
#define M_FILE_IMPORT 1060
#define M_FILE_EXPORT 1061
#define M_NUMSYS_DEC 1062
#define M_NUMSYS_BIN 1063
#define M_NUMSYS_OCT 1064
#define M_NUMSYS_HEX 1065
#define M_HISTORY_OPEN 1066
#define M_HISTORY_CLEAR 1067
#define M_SIZE_OPEN 1068
#define BTN_LOGIC_GATE_NOT 1069
#define BTN_MISC_DOT 1070


class main : public wxFrame
{
	private:
		int currentNumSystem = M_NUMSYS_DEC; // decimal

	protected:
		void handleNumberSystemChange(wxCommandEvent& event);
		void handleNumButtons(wxCommandEvent& event);
		void handleSquareRoot(wxCommandEvent& event);
		void handleOperations(wxCommandEvent& event);
		void handleFunction(wxCommandEvent& event);
		void handleClear(wxCommandEvent& event);
		void handleBackspace(wxCommandEvent& event);
		void handleShowHistory(wxCommandEvent& event);
		void handleClearHistory(wxCommandEvent& event);
		void handleFileImport(wxCommandEvent& event);
		void handleResult(wxCommandEvent& event);
		void handleSize(wxCommandEvent& event);
		void handleNumLogicButtons(wxCommandEvent& event);
		void handleLogicOperations(wxCommandEvent& event);
		void handleLogicBackspace(wxCommandEvent& event);
		void handleLogicClear(wxCommandEvent& event);
		void handleLogicResult (wxCommandEvent& event);
		wxNotebook* main_notebook;
		wxPanel* m_panel_arithemtic;
		wxTextCtrl* textInput;
		wxButton* btn_leftBrckt;
		wxButton* btn_rightBrckt;
		wxButton* btn_modus;
		wxButton* btn_backspace;
		wxButton* btn_multiply;
		wxButton* btn_exponent;
		wxButton* btn_root;
		wxButton* m_fill;
		wxButton* btn_clear;
		wxButton* btn_divide;
		wxButton* btn_num1;
		wxButton* btn_num2;
		wxButton* btn_num3;
		wxButton* btn_num4;
		wxButton* btn_subtract;
		wxButton* btn_num5;
		wxButton* btn_num6;
		wxButton* btn_num7;
		wxButton* btn_num8;
		wxButton* btn_addition;
		wxButton* btn_num9;
		wxButton* btn_num0;
		wxButton* btn_hexA;
		wxButton* btn_hexB;
		wxButton* btn_result;
		wxButton* btn_hexC;
		wxButton* btn_hexD;
		wxButton* btn_hexE;
		wxButton* btn_hexF;
		wxPanel* m_panel_logic;
		wxTextCtrl* logictextInput;
		wxButton* btn_logic_AND;
		wxButton* btn_logic_OR;
		wxButton* btn_logic_NOT;
		wxButton* btn_logic_clear;
		wxButton* btn_logic_backspace;
		wxButton* btn_logic_NAND;
		wxButton* btn_logic_NOR;
		wxButton* btn_logic_XOR;
		wxButton* btn_logic_XNOR;
		wxButton* btn_logic_leftBrckt;
		wxButton* btn_logic_num1;
		wxButton* btn_logic_num2;
		wxButton* btn_logic_num3;
		wxButton* btn_logic_num4;
		wxButton* btn_logic_rightBrckt;
		wxButton* btn_logic_num5;
		wxButton* btn_logic_num6;
		wxButton* btn_logic_num7;
		wxButton* btn_logic_num8;
		wxButton* btn_logic_result;
		wxButton* btn_logic_num9;
		wxButton* btn_logic_num0;
		wxButton* btn_logic_num_hexA;
		wxButton* btn_logic_num_hexB;
		wxButton* btn_logic_num_hexC;
		wxButton* btn_logic_num_hexD;
		wxButton* btn_logic_num_hexE;
		wxButton* btn_logic_num_hexF;
		wxStatusBar* m_statusBar;
		wxMenuBar* m_calcmenu;
		wxMenu* m_file;
		wxMenu* m_numberSystem;
		wxMenuItem* mi_Binary;
		wxMenuItem* mi_Decimal;
		wxMenu* m_history;
		wxMenu* m_size;
		HistoryDialog* history_dialog;
		sizeDialog* size_dialog;
		wxFileDialog* file_dialog;
		logicParser* logic_parser;
		arithmeticParser* arithmetic_parser;
		numConverter* numCnvrt;


	public:

		main(wxWindow * parent, wxWindowID id = wxID_ANY, const wxString & title = wxT("Kalkulator"), const wxPoint & pos = wxDefaultPosition, const wxSize & size = wxSize(650, 503), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

		~main();
		wxDECLARE_EVENT_TABLE();
};