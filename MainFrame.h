#ifndef EDITOR_MAINFRAME_H
#define EDITOR_MAINFRAME_H

#include <wx/richtext/richtextxml.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title, int xPos, int yPos, int width, int height);

    void OnMenuFileOpen(wxCommandEvent &event);
    void OnMenuFileSave(wxCommandEvent &event);
    void OnMenuFileQuit(wxCommandEvent &event);

    DECLARE_EVENT_TABLE()
private:
    wxMenuBar *mpMenuBar;
    wxMenu *mpFileMenu;
    wxRichTextCtrl *mpTextField;
};


#endif //EDITOR_MAINFRAME_H
