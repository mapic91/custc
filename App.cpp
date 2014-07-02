/***************************************************************
 * Name:      App.cpp
 * Purpose:   Code for Application Class
 * Author:
 * Created:
 * Copyright:
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "App.h"
#include "MainFrame.h"
#include <wx/image.h>

IMPLEMENT_APP(wxWidgets_templateApp);

bool wxWidgets_templateApp::OnInit()
{
	bool wxsOK = true;
	wxInitAllImageHandlers();

	MainFrame *frm = new MainFrame(NULL);
	frm->Show();

	return wxsOK;
}
