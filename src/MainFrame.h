#ifndef EDITOR_MAINFRAME_H
#define EDITOR_MAINFRAME_H

#include <wx/richtext/richtextxml.h>

#include "InstrumentPanel.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title, int xPos, int yPos, int width, int height);

    void OnMenuFileOpen(wxCommandEvent &event);
    void OnMenuFileSave(wxCommandEvent &event);
    void OnMenuFileSaveAs(wxCommandEvent &event);
    void OnMenuFileQuit(wxCommandEvent &event);

    void OnMenuEditUndo(wxCommandEvent &event);
    void OnMenuEditRedo(wxCommandEvent &event);

    void OnMenuEditCopy(wxCommandEvent &event);
    void OnMenuEditCut(wxCommandEvent &event);
    void OnMenuEditPaste(wxCommandEvent &event);

    void OnUpdate(wxRichTextEvent &event);

    DECLARE_EVENT_TABLE()
private:
    wxMenuBar *mpMenuBar;
    wxMenu *mpFileMenu;
    wxMenu *mpEditMenu;
    wxRichTextCtrl *mpTextField;
    InstrumentPanel *mpInstrumentPanel;

    wxString fileName;
};

#endif //EDITOR_MAINFRAME_H
