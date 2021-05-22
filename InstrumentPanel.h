#ifndef EDITOR_INSTRUMENTPANEL_H
#define EDITOR_INSTRUMENTPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/richtext/richtextctrl.h>

class InstrumentPanel : public wxPanel {
public:
    InstrumentPanel(wxWindow *parent, wxRichTextCtrl& textField);

    void OnBoldButton(wxCommandEvent& event);
    void OnItalicButton(wxCommandEvent& event);
    void OnUnderlineButton(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
private:
    wxButton *mpBoldButton;
    wxButton *mpItalicButton;
    wxButton *mpUnderlineButton;
    wxRichTextCtrl& mrTextField;
};

#endif //EDITOR_INSTRUMENTPANEL_H
