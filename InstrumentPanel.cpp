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

        mpBiggerSizeButton = new wxButton(this, wxID_AUTO_HIGHEST, _T(""), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpBiggerSizeButton);
        mpSmallerSizeButton = new wxButton(this, wxID_AUTO_LOWEST, _T(""), wxDefaultPosition, wxSize(50, 100));
        pSizer->Add(mpSmallerSizeButton);
        wxStaticText *pTextSize = new wxStaticText(this, TEXT_SIZE_FIELD_ID, "10");
        pSizer->Add(pTextSize);

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
    wxRichTextAttr style;
    if(mrTextField.HasSelection()) {
        wxRichTextRange range = mrTextField.GetSelectionRange();
        mrTextField.GetStyleForRange(range, style);
        style.SetFontSize(style.GetFontSize() + 2);
        mrTextField.SetStyle(range, style);
    }
    else {
        mrTextField.GetStyle(mrTextField.GetCaretPosition(), style);
        mrTextField.EndFontSize();
        mrTextField.BeginFontSize(style.GetFontSize() + 10);
    }
    mrTextField.SetFocus();
}

void InstrumentPanel::OnSmallerSizeButton(wxCommandEvent& event) {
    mrTextField.EndFontSize();
    mrTextField.BeginFontSize(10);
    mrTextField.SetFocus();
}