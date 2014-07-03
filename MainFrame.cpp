///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "JxqyStc.h"

#include "MainFrame.h"
#include "wx/msgdlg.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_scintilla1 = new JxqyStc( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	m_scintilla1->SetUseTabs( true );
	m_scintilla1->SetTabWidth( 4 );
	m_scintilla1->SetIndent( 4 );
	m_scintilla1->SetTabIndents( false );
	m_scintilla1->SetBackSpaceUnIndents( false );
	m_scintilla1->SetFunctionKeywordFromFile(wxT("E:\\temp\\ProgramingTemp\\cusstc\\jxqy2.txt"));
	bSizer1->Add( m_scintilla1, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}
