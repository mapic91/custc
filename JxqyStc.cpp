#include "JxqyStc.h"
#include "wx/textfile.h"

JxqyStc::JxqyStc(wxWindow *parent,
               wxWindowID id,
               const wxPoint &pos,
               const wxSize &size,
               long style,
               const wxString &name)
:wxStyledTextCtrl(parent, id, pos, size, style, name)
{
    StyleClearAll();

    SetLexer(wxSTC_LEX_JXQY);
    wxFont font(12, wxMODERN, wxNORMAL, wxNORMAL);
    SetDefaultFont(font);
    SetDefaultBackgroundColour(wxColour(192, 255, 185));
    StyleSetBackground(wxSTC_STYLE_DEFAULT, wxColour(192, 255, 185));
    StyleSetForeground(wxSTC_JXQY_COMMENT, wxColour(160, 160, 160));
    //StyleSetForeground(wxSTC_JXQY_KEYWORD, wxColour(0, 255, 0));
    StyleSetForeground(wxSTC_JXQY_FUNCTION, wxColour(255, 128, 0));
    StyleSetForeground(wxSTC_JXQY_OPERATOR, wxColour(255, 0, 0));
    StyleSetForeground(wxSTC_JXQY_STRING, wxColour(0, 0, 255));
    StyleSetForeground(wxSTC_JXQY_GOTOPOS, wxColour(201,84,218));
    StyleSetForeground(wxSTC_JXQY_VARIABLE, wxColour(50,167,120));
    StyleSetForeground(wxSTC_JXQY_NUMBER, wxColour(255,128,255));
    SetTabWidth(4);
    SetIndent(4);
    SetUseTabs(true);
    SetTabIndents (false);
    SetBackSpaceUnIndents(false);
    SetIndentationGuides(true);

    AutoCompSetIgnoreCase(true);
    AutoCompSetMaxWidth(20);

    this->GetEventHandler()->Bind(wxEVT_STC_CHARADDED, &JxqyStc::OnCharAdded, this);
}

JxqyStc::~JxqyStc()
{
    this->Unbind(wxEVT_STC_CHARADDED, &JxqyStc::OnCharAdded, this);
}

void JxqyStc::OnCharAdded(wxStyledTextEvent &event)
{
    //Auto indent
    char chr = (char)event.GetKey();
    int currentLine = GetCurrentLine();
    if (chr == '\n' || chr == '\r')
    {
        int lineInd = 0;
        if (currentLine > 0) {
            lineInd = GetLineIndentation(currentLine - 1);
        }
        if (lineInd != 0)
		{
			SetLineIndentation (currentLine, lineInd);
			GotoPos(PositionFromLine (currentLine) + lineInd);
		}
    }


    //Auto complete
    int curline =  GetCurrentLine();
    int startPos = PositionFromLine(curline);
    int curPos = GetCurrentPos();
    int lineLenBefCaret = curPos - startPos;
    wxString lineStr = GetCurLine();
    lineStr = lineStr.Mid(0, lineLenBefCaret);
    lineStr.Trim(false);

    int lineLen = lineStr.length(), hintLen = 0;
    while(hintLen < lineLen)
        if(lineStr[lineLen - hintLen - 1] != wxChar(' '))
            hintLen++;
        else
            break;
    if(hintLen > 2)
    {
        if(!AutoCompActive())
            AutoCompShow(hintLen, m_functionKeyword);
    }
}

void JxqyStc::SetFunctionKeywordFromFile(const wxString &filename)
{
	wxTextFile file;
	if(!file.Open(filename, wxConvLibc)) return;
	wxArrayString words;
}
