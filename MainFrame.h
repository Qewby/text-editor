#ifndef EDITOR_MAINFRAME_H
#define EDITOR_MAINFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title, int xPos, int yPos, int width, int height);

private:
    wxMenuBar *mpMenuBar;
    wxMenu *mpFileMenu;
};


#endif //EDITOR_MAINFRAME_H
