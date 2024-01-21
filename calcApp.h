#pragma once
#include "wx/wx.h"
#include "main.h"
class calcApp : public wxApp
{
public:
	calcApp();
	virtual bool OnInit();
private:
	main* m_frame1 = nullptr;
};

