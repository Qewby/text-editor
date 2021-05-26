#ifndef EDITOR_INSTRUMENTPANEL_H
#define EDITOR_INSTRUMENTPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/richtext/richtextctrl.h>
#include <wx/clrpicker.h>

class InstrumentPanel : public wxPanel {
public:
    InstrumentPanel(wxWindow *parent, wxRichTextCtrl& textField);

    void Update();
    void SetFontSize(int size);

    void OnBoldButton(wxCommandEvent& event);
    void OnItalicButton(wxCommandEvent& event);
    void OnUnderlineButton(wxCommandEvent& event);

    void OnAlignLeftButton(wxCommandEvent& event);
    void OnAlignRightButton(wxCommandEvent& event);
    void OnAlignCenterButton(wxCommandEvent& event);

    void OnBiggerSizeButton(wxCommandEvent& event);
    void OnSmallerSizeButton(wxCommandEvent& event);
    void OnFontSizeChange(wxCommandEvent& event);



    DECLARE_EVENT_TABLE()
private:
    wxButton *mpBoldButton;
    wxButton *mpItalicButton;
    wxButton *mpUnderlineButton;

    wxButton *mpAlignLeftButton;
    wxButton *mpAlignCenterButton;
    wxButton *mpAlignRightButton;

    wxButton *mpBiggerSizeButton;
    wxButton *mpSmallerSizeButton;
    wxComboBox *mpFontSizeBox;
    wxArrayString mFontSizesArray;

    wxRichTextCtrl& mrTextField;
};

enum {
    TEXT_FIELD_ID = wxID_HIGHEST + 1,
    TEXT_SIZE_FIELD_ID = wxID_HIGHEST + 2
};

#endif //EDITOR_INSTRUMENTPANEL_H
