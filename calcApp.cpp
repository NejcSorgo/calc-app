#include "calcApp.h"

wxIMPLEMENT_APP(calcApp);
calcApp::calcApp() {

}
bool calcApp::OnInit()
{
	m_frame1 = new main(nullptr);
	m_frame1->Show();
	return true;
}