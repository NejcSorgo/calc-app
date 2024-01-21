#pragma once
#include "main.h"
class calcApp : public wxApp
{
public:
	calcApp();
	virtual bool OnInit();
private:
	main* m_frame1 = nullptr;
};

