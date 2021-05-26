#ifndef EDITOR_INSTRUMENTPANEL_H
#define EDITOR_INSTRUMENTPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/richtext/richtextctrl.h>
#include <wx/clrpicker.h>
#include <wx/fontenum.h>

class InstrumentPanel : public wxPanel {
public:
    InstrumentPanel(wxWindow *parent, wxRichTextCtrl& textField);

    void Update();
    void SetFontSize(int size);

    void OnBoldButton(wxCommandEvent &event);
    void OnItalicButton(wxCommandEvent &event);
    void OnUnderlineButton(wxCommandEvent &event);

    void OnAlignLeftButton(wxCommandEvent &event);
    void OnAlignRightButton(wxCommandEvent &event);
    void OnAlignCenterButton(wxCommandEvent &event);

    void OnFontChange(wxCommandEvent &event);

    void OnBiggerSizeButton(wxCommandEvent &event);
    void OnSmallerSizeButton(wxCommandEvent &event);
    void OnFontSizeChange(wxCommandEvent &event);

    void OnTextColourChange(wxColourPickerEvent &event);
    void OnTextBackgroundColourChange(wxColourPickerEvent &event);

    DECLARE_EVENT_TABLE()
private:
    wxButton *mpBoldButton;
    wxButton *mpItalicButton;
    wxButton *mpUnderlineButton;

    wxButton *mpAlignLeftButton;
    wxButton *mpAlignCenterButton;
    wxButton *mpAlignRightButton;

    wxComboBox *mpFontBox;
    wxComboBox *mpFontSizeBox;
    wxArrayString mFontSizesArray;
    wxButton *mpBiggerSizeButton;
    wxButton *mpSmallerSizeButton;

    wxColourPickerCtrl *mpTextColourPicker;
    wxColourPickerCtrl *mpTextBackgroundColourPicker;

    wxRichTextAttr mCaretStyle;
    wxRichTextCtrl &mrTextField;
};

enum {
    TEXT_FIELD_ID = wxID_HIGHEST + 1,
    TEXT_SIZE_FIELD_ID = wxID_HIGHEST + 2,
    TEXT_COLOUR_PICKER_ID = wxID_HIGHEST + 3,
    TEXT_BACKGROUND_COLOUR_PICKER_ID = wxID_HIGHEST + 4,
    TEXT_FONT_FIELD_ID = wxID_HIGHEST + 5
};

#endif //EDITOR_INSTRUMENTPANEL_H
