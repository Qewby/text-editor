#include "InstrumentPanel.h"

BEGIN_EVENT_TABLE(InstrumentPanel, wxPanel)
    EVT_BUTTON(wxID_BOLD, InstrumentPanel::OnBoldButton)
    EVT_BUTTON(wxID_ITALIC, InstrumentPanel::OnItalicButton)
    EVT_BUTTON(wxID_UNDERLINE, InstrumentPanel::OnUnderlineButton)

    EVT_BUTTON(wxID_JUSTIFY_LEFT, InstrumentPanel::OnAlignLeftButton)
    EVT_BUTTON(wxID_JUSTIFY_CENTER, InstrumentPanel::OnAlignCenterButton)
    EVT_BUTTON(wxID_JUSTIFY_RIGHT, InstrumentPanel::OnAlignRightButton)

    EVT_COMBOBOX(TEXT_FONT_FIELD_ID, InstrumentPanel::OnFontChange)
    EVT_TEXT_ENTER(TEXT_FONT_FIELD_ID, InstrumentPanel::OnFontChange)

    EVT_BUTTON(wxID_AUTO_HIGHEST, InstrumentPanel::OnBiggerSizeButton)
    EVT_BUTTON(wxID_AUTO_LOWEST, InstrumentPanel::OnSmallerSizeButton)
    EVT_COMBOBOX(TEXT_SIZE_FIELD_ID, InstrumentPanel::OnFontSizeChange)
    EVT_TEXT_ENTER(TEXT_SIZE_FIELD_ID, InstrumentPanel::OnFontSizeChange)

    EVT_COLOURPICKER_CHANGED(TEXT_COLOUR_PICKER_ID, InstrumentPanel::OnTextColourChange)
    EVT_COLOURPICKER_CHANGED(TEXT_BACKGROUND_COLOUR_PICKER_ID, InstrumentPanel::OnTextBackgroundColourChange)
END_EVENT_TABLE()

InstrumentPanel::InstrumentPanel(wxWindow *parent, wxRichTextCtrl& textField, int width)
    : mrTextField(textField), wxPanel(parent, wxID_ANY, wxPoint(0, 0),
                                      wxSize(width, 50))
    {
        wxBoxSizer *pSizer = new wxBoxSizer(wxHORIZONTAL);

        //Bold, italic, underline buttons
        mpBoldButton = new wxButton(this, wxID_BOLD, wxEmptyString, wxDefaultPosition,
                                    wxSize(1, 50));
        mpItalicButton = new wxButton(this, wxID_ITALIC, wxEmptyString, wxDefaultPosition,
                                      wxSize(1, 50));
        mpUnderlineButton = new wxButton(this, wxID_UNDERLINE, wxEmptyString, wxDefaultPosition,
                                         wxSize(1, 50));

        //Text alignment buttons
        mpAlignLeftButton = new wxButton(this, wxID_JUSTIFY_LEFT, wxEmptyString, wxDefaultPosition,
                                         wxSize(1, 50));
        mpAlignCenterButton = new wxButton(this, wxID_JUSTIFY_CENTER, wxEmptyString, wxDefaultPosition,
                                           wxSize(1, 50));
        mpAlignRightButton = new wxButton(this, wxID_JUSTIFY_RIGHT, wxEmptyString, wxDefaultPosition,
                                          wxSize(1, 50));

        //Font and font size boxes
        mpFontBox = new wxComboBox(this, TEXT_FONT_FIELD_ID, wxEmptyString, wxDefaultPosition,
                                   wxSize(1, 50), wxFontEnumerator::GetFacenames(), wxTE_PROCESS_ENTER);
        mFontSizesArray.Add(_T("8"));
        mFontSizesArray.Add(_T("9"));
        mFontSizesArray.Add(_T("10"));
        mFontSizesArray.Add(_T("11"));
        mFontSizesArray.Add(_T("12"));
        mFontSizesArray.Add(_T("14"));
        mFontSizesArray.Add(_T("18"));
        mFontSizesArray.Add(_T("24"));
        mFontSizesArray.Add(_T("30"));
        mFontSizesArray.Add(_T("36"));
        mFontSizesArray.Add(_T("48"));
        mFontSizesArray.Add(_T("60"));
        mFontSizesArray.Add(_T("72"));
        mpFontSizeBox = new wxComboBox(this, TEXT_SIZE_FIELD_ID, _T("10"), wxDefaultPosition,
                                       wxSize(1, 50), mFontSizesArray, wxTE_PROCESS_ENTER);
        mpBiggerSizeButton = new wxButton(this, wxID_AUTO_HIGHEST, wxEmptyString, wxDefaultPosition,
                                          wxSize(1, 50));
        mpBiggerSizeButton->SetBitmapLabel(wxArtProvider::GetBitmap(wxART_GO_UP));
        mpSmallerSizeButton = new wxButton(this, wxID_AUTO_LOWEST, wxEmptyString, wxDefaultPosition,
                                           wxSize(1, 50));
        mpSmallerSizeButton->SetBitmapLabel(wxArtProvider::GetBitmap(wxART_GO_DOWN));

        //Text and background colour pickers
        mpTextColourPicker = new wxColourPickerCtrl(this, TEXT_COLOUR_PICKER_ID, *wxBLACK, wxDefaultPosition,
                                                    wxSize(1, 50));
        mpTextBackgroundColourPicker = new wxColourPickerCtrl(this, TEXT_BACKGROUND_COLOUR_PICKER_ID,
                                                              *wxWHITE, wxDefaultPosition, wxSize(1, 50));

        pSizer->Add(mpBoldButton, 4, wxEXPAND);
        pSizer->Add(mpItalicButton, 4, wxEXPAND);
        pSizer->Add(mpUnderlineButton, 6, wxEXPAND);
        pSizer->AddSpacer(20);
        pSizer->Add(mpAlignLeftButton, 5, wxEXPAND);
        pSizer->Add(mpAlignCenterButton, 5, wxEXPAND);
        pSizer->Add(mpAlignRightButton, 5, wxEXPAND);
        pSizer->AddSpacer(20);
        pSizer->Add(mpFontBox, 10, wxEXPAND);
        pSizer->Add(mpFontSizeBox, 5, wxEXPAND);
        pSizer->Add(mpBiggerSizeButton, 5, wxEXPAND);
        pSizer->Add(mpSmallerSizeButton, 5, wxEXPAND);
        pSizer->AddSpacer(20);
        pSizer->Add(mpTextColourPicker, 5, wxEXPAND);
        pSizer->Add(mpTextBackgroundColourPicker, 5, wxEXPAND);

        SetSizer(pSizer);
}

void InstrumentPanel::OnBoldButton(wxCommandEvent &event) {
    if(mrTextField.HasSelection()) {
        mrTextField.ApplyBoldToSelection();
    }
    else if (mrTextField.IsSelectionBold()) {
        mrTextField.EndBold();
    }
    else {
        mrTextField.BeginBold();
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnItalicButton(wxCommandEvent &event) {
    if(mrTextField.HasSelection()) {
        mrTextField.ApplyItalicToSelection();
    }
    else if (mrTextField.IsSelectionItalics()) {
        while(!mrTextField.EndItalic());
    }
    else {
        while(!mrTextField.BeginItalic());
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnUnderlineButton(wxCommandEvent &event) {
    if(mrTextField.HasSelection()) {
        mrTextField.ApplyUnderlineToSelection();
    }
    else if (mrTextField.IsSelectionUnderlined()) {
        while(!mrTextField.EndUnderline());
    }
    else {
        while(!mrTextField.BeginUnderline());
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnAlignLeftButton(wxCommandEvent& event) {
    mrTextField.ApplyAlignmentToSelection(wxTEXT_ALIGNMENT_LEFT);
    mrTextField.SetFocus();
}

void InstrumentPanel::OnAlignRightButton(wxCommandEvent& event) {
    mrTextField.ApplyAlignmentToSelection(wxTEXT_ALIGNMENT_RIGHT);
    mrTextField.SetFocus();
}

void InstrumentPanel::OnAlignCenterButton(wxCommandEvent& event) {
    mrTextField.ApplyAlignmentToSelection(wxTEXT_ALIGNMENT_CENTRE);
    mrTextField.SetFocus();
}

void InstrumentPanel::OnBiggerSizeButton(wxCommandEvent& event) {
    long nowFontSize;
    long fontSize;
    mpFontSizeBox->GetValue().ToLong(&nowFontSize);
    int arraySize = mpFontSizeBox->GetStrings().GetCount();
    int i;
    for (i = 0; i < arraySize; i++) {
        mpFontSizeBox->GetString(i).ToLong(&fontSize);
        if (nowFontSize < fontSize) {
            SetFontSize(fontSize);
            mpFontSizeBox->SetValue(mpFontSizeBox->GetString(i));
            return;
        }
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnSmallerSizeButton(wxCommandEvent& event) {
    long nowFontSize;
    long fontSize;
    mpFontSizeBox->GetValue().ToLong(&nowFontSize);
    int arraySize = mpFontSizeBox->GetStrings().GetCount();
    int i;
    for (i = arraySize - 1; i >= 0; i--) {
        mpFontSizeBox->GetString(i).ToLong(&fontSize);
        if (nowFontSize > fontSize) {
            SetFontSize(fontSize);
            mpFontSizeBox->SetValue(mpFontSizeBox->GetString(i));
            return;
        }
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnFontSizeChange(wxCommandEvent &event) {
    long fontSize;
    event.GetString().ToLong(&fontSize);
    SetFontSize(fontSize);
}

void InstrumentPanel::SetFontSize(int size) {
    if(mrTextField.HasSelection()) {
        wxRichTextAttr style;
        wxRichTextRange range = mrTextField.GetSelectionRange();
        mrTextField.GetStyleForRange(range, style);
        style.SetFontSize(size);
        mrTextField.SetStyle(range, style);
    }
    else {
        mCaretStyle.SetFontSize(size);
        mrTextField.EndStyle();
        mrTextField.BeginStyle(mCaretStyle);
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnTextColourChange(wxColourPickerEvent &event) {
    if(mrTextField.HasSelection()) {
        wxRichTextAttr style;
        wxRichTextRange range = mrTextField.GetSelectionRange();
        mrTextField.GetStyleForRange(range, style);
        style.SetTextColour(event.GetColour());
        mrTextField.SetStyle(range, style);
    }
    else {
        mCaretStyle.SetTextColour(event.GetColour());
        mrTextField.EndStyle();
        mrTextField.BeginStyle(mCaretStyle);
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnTextBackgroundColourChange(wxColourPickerEvent &event) {
    if(mrTextField.HasSelection()) {
        wxRichTextAttr style;
        wxRichTextRange range = mrTextField.GetSelectionRange();
        mrTextField.GetStyleForRange(range, style);
        style.SetBackgroundColour(event.GetColour());
        mrTextField.SetStyle(range, style);
    }
    else {
        mCaretStyle.SetBackgroundColour(event.GetColour());
        mrTextField.EndStyle();
        mrTextField.BeginStyle(mCaretStyle);
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnFontChange(wxCommandEvent &event) {
    if(mrTextField.HasSelection()) {
        wxRichTextAttr style;
        wxRichTextRange range = mrTextField.GetSelectionRange();
        mrTextField.GetStyleForRange(range, style);
        style.SetFontFaceName(event.GetString());
        mrTextField.SetStyle(range, style);
    }
    else {
        mCaretStyle.SetFontFaceName(event.GetString());
        mrTextField.EndStyle();
        mrTextField.BeginStyle(mCaretStyle);
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::Update() {
    wxRichTextAttr style;
    mrTextField.GetStyle(mrTextField.GetCaretPosition(), style);
    mCaretStyle = style;
    wxString fontSize = wxString::Format(wxT("%i"), mCaretStyle.GetFontSize());
    mpFontSizeBox->SetValue(fontSize);
    mpTextColourPicker->SetColour(mCaretStyle.GetTextColour());
    wxColour colour = mCaretStyle.GetBackgroundColour();
    if (colour == wxNullColour) {
        colour.Set(255, 255, 255, 255);
    }
    mpTextBackgroundColourPicker->SetColour(colour);
    mpFontBox->SetValue(style.GetFontFaceName());
}