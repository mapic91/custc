#ifndef JxqyStc_H
#define JxqyStc_H

#include "wx/stc/stc.h"
class JxqyStc: public wxStyledTextCtrl
{
public:
    JxqyStc(wxWindow *parent,
            wxWindowID id=wxID_ANY,
            const wxPoint &pos=wxDefaultPosition,
            const wxSize &size=wxDefaultSize,
            long style=0,
            const wxString &name=wxSTCNameStr);
    virtual ~JxqyStc();

    void SetDefaultFont(wxFont &font)
    {
        for(int i = 0; i <= wxSTC_STYLE_DEFAULT; i++)
        {
            StyleSetFont(i, font);
        }
    }
    void SetDefaultForegroundColour(const wxColour &colour)
    {
        for(int i = 0; i <= wxSTC_STYLE_DEFAULT; i++)
        {
            StyleSetForeground(i, colour);
        }
    }
    void SetDefaultBackgroundColour(const wxColour &colour)
    {
        for(int i = 0; i <= wxSTC_STYLE_DEFAULT; i++)
        {
            StyleSetBackground(i, colour);
        }
    }
    void SetFunctionKeyword(const wxString &words)
    {
        SetKeyWords(1, words);
        m_functionKeyword = words;
    }
    //Set keywors, the space in words is striped
    void SetFunctionKeyword(wxArrayString &words)
    {
        words.Sort();
        m_functionKeyword.Clear();
        size_t counts = words.Count();
        wxString word;
        for(size_t i = 0; i < counts; i++)
        {
            word = words[i];
            word.Replace(wxT(" "), wxT(""));
            m_functionKeyword += word;
            if(i != counts - 1)
				m_functionKeyword += wxT(" ");
        }
        SetKeyWords(1, m_functionKeyword);
    }
    void SetFunctionKeywordFromFile(const wxString &filename);
protected:
private:
	//Contents in ( ) is removed
    wxString StripFunctionKeyword(const wxString &word)
    {
        wxString stripedWord;
        bool begBrace = false;
        bool endBrace = true;
        size_t len = word.Length();
        for(size_t j = 0; j < len; j++)
        {
        	if(begBrace && word[j] == wxChar(')'))
            {
                endBrace = true;
                begBrace = false;
            }
            if(endBrace)
                stripedWord += word[j];
			if(endBrace && word[j] == wxChar('('))
            {
                begBrace = true;
                endBrace = false;
            }
        }
        return stripedWord;
    }


    void OnCharAdded(wxStyledTextEvent &event);
    wxString m_functionKeyword;
};

#endif // JxqyStc_H
