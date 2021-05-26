#include "InstrumentPanel.h"

BEGIN_EVENT_TABLE(InstrumentPanel, wxPanel)
    EVT_BUTTON(wxID_BOLD, InstrumentPanel::OnBoldButton)
    EVT_BUTTON(wxID_ITALIC, InstrumentPanel::OnItalicButton)
    EVT_BUTTON(wxID_UNDERLINE, InstrumentPanel::OnUnderlineButton)

    EVT_BUTTON(wxID_JUSTIFY_LEFT, InstrumentPanel::OnAlignLeftButton)
    EVT_BUTTON(wxID_JUSTIFY_CENTER, InstrumentPanel::OnAlignCenterButton)
    EVT_BUTTON(wxID_JUSTIFY_RIGHT, InstrumentPanel::OnAlignRightButton)

    EVT_BUTTON(wxID_AUTO_HIGHEST, InstrumentPanel::OnBiggerSizeButton)
    EVT_BUTTON(wxID_AUTO_LOWEST, InstrumentPanel::OnSmallerSizeButton)
    EVT_COMBOBOX(TEXT_SIZE_FIELD_ID, InstrumentPanel::OnFontSizeChange)
    EVT_TEXT_ENTER(TEXT_SIZE_FIELD_ID, InstrumentPanel::OnFontSizeChange)

    EVT_COLOURPICKER_CHANGED(TEXT_COLOUR_PICKER_ID, InstrumentPanel::OnTextColourChange)
    EVT_COLOURPICKER_CHANGED(TEXT_BACKGROUND_COLOUR_PICKER_ID, InstrumentPanel::OnTextBackgroundColourChange)
END_EVENT_TABLE()

InstrumentPanel::InstrumentPanel(wxWindow *parent, wxRichTextCtrl& textField)
    : mrTextField(textField), wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(800, 50))
    {
        wxBoxSizer *pSizer = new wxBoxSizer(wxHORIZONTAL);

        mpBoldButton = new wxButton(this, wxID_BOLD, _T(""), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpBoldButton);
        mpItalicButton = new wxButton(this, wxID_ITALIC, _T(""), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpItalicButton);
        mpUnderlineButton = new wxButton(this, wxID_UNDERLINE, _T(""), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpUnderlineButton);

        mpAlignLeftButton = new wxButton(this, wxID_JUSTIFY_LEFT, _T(""), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpAlignLeftButton);
        mpAlignCenterButton = new wxButton(this, wxID_JUSTIFY_CENTER, _T(""), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpAlignCenterButton);
        mpAlignRightButton = new wxButton(this, wxID_JUSTIFY_RIGHT, _T(""), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpAlignRightButton);

        mpBiggerSizeButton = new wxButton(this, wxID_AUTO_HIGHEST, _T("Bigger"), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpBiggerSizeButton);
        mpSmallerSizeButton = new wxButton(this, wxID_AUTO_LOWEST, _T("Lower"), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpSmallerSizeButton);
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
                                       wxSize(50, 300), mFontSizesArray, wxTE_PROCESS_ENTER);
        pSizer->Add(mpFontSizeBox, 3);

        mpTextColourPicker = new wxColourPickerCtrl(this, TEXT_COLOUR_PICKER_ID);
        pSizer->Add(mpTextColourPicker, 3);
        mpTextBackgroundColourPicker = new wxColourPickerCtrl(this, TEXT_BACKGROUND_COLOUR_PICKER_ID, *wxWHITE);
        pSizer->Add(mpTextBackgroundColourPicker, 3);

        SetSizer(pSizer);
}

void InstrumentPanel::OnBoldButton(wxCommandEvent &event) {
    static bool isBold = false;
    if(mrTextField.HasSelection()) {
        mrTextField.ApplyBoldToSelection();
    }
    else if (isBold) {
        isBold = !isBold;
        while(!mrTextField.EndBold());
    }
    else {
        isBold = !isBold;
        while(!mrTextField.BeginBold());
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnItalicButton(wxCommandEvent &event) {
    static bool isItalic = false;
    if(mrTextField.HasSelection()) {
        mrTextField.ApplyItalicToSelection();
    }
    else if (isItalic) {
        isItalic = !isItalic;
        while(!mrTextField.EndItalic());
    }
    else {
        isItalic = !isItalic;
        while(!mrTextField.BeginItalic());
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnUnderlineButton(wxCommandEvent &event) {
    static bool isUnderline = false;
    if(mrTextField.HasSelection()) {
        mrTextField.ApplyUnderlineToSelection();
    }
    else if (isUnderline) {
        isUnderline = !isUnderline;
        while(!mrTextField.EndUnderline());
    }
    else {
        isUnderline = !isUnderline;
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
    wxRichTextAttr style;
    if(mrTextField.HasSelection()) {
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

void InstrumentPanel::Update() {
    wxRichTextAttr style;
    mrTextField.GetStyle(mrTextField.GetCaretPosition(), style);
    mCaretStyle = style;
    wxString fontSize = wxString::Format(wxT("%i"), mCaretStyle.GetFontSize());
    mpFontSizeBox->SetValue(fontSize);
    mpTextColourPicker->SetColour(mCaretStyle.GetTextColour());
    wxColour colour = mCaretStyle.GetBackgroundColour();
    if (colour != wxNullColour) {
        mpTextBackgroundColourPicker->SetColour(colour);
    }
}