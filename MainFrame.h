#ifndef EDITOR_MAINFRAME_H
#define EDITOR_MAINFRAME_H

#include <wx/richtext/richtextxml.h>

#include "InstrumentPanel.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title, int xPos, int yPos, int width, int height);

    void OnMenuFileOpen(wxCommandEvent &event);
    void OnMenuFileSave(wxCommandEvent &event);
    void OnMenuFileQuit(wxCommandEvent &event);

    void OnUpdate(wxRichTextEvent &event);

    DECLARE_EVENT_TABLE()
private:
    wxMenuBar *mpMenuBar;
    wxMenu *mpFileMenu;
    wxRichTextCtrl *mpTextField;
    InstrumentPanel *mpInstrumentPanel;
};

#endif //EDITOR_MAINFRAME_H
