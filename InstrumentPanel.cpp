#include "InstrumentPanel.h"

BEGIN_EVENT_TABLE(InstrumentPanel, wxPanel)
    EVT_BUTTON(wxID_BOLD, InstrumentPanel::OnBoldButton)
    EVT_BUTTON(wxID_ITALIC, InstrumentPanel::OnItalicButton)
    EVT_BUTTON(wxID_UNDERLINE, InstrumentPanel::OnUnderlineButton)
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

        SetSizer(pSizer);
}

void InstrumentPanel::OnBoldButton(wxCommandEvent &event) {
    static bool isBold = false;
    if(mrTextField.HasSelection()) {
        mrTextField.ApplyBoldToSelection();
    }
    else if (isBold) {
        mpBoldButton->SetBackgroundColour(wxColour(255, 0, 0));
        isBold = !isBold;
        while(!mrTextField.EndBold());
    }
    else {
        mpBoldButton->SetBackgroundColour(wxColour(0, 255, 0));
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
        mpItalicButton->SetBackgroundColour(wxColour(255, 0, 0));
        isItalic = !isItalic;
        while(!mrTextField.EndItalic());
    }
    else {
        mpItalicButton->SetBackgroundColour(wxColour(0, 255, 0));
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
        mpUnderlineButton->SetBackgroundColour(wxColour(255, 0, 0));
        isUnderline = !isUnderline;
        while(!mrTextField.EndUnderline());
    }
    else {
        mpUnderlineButton->SetBackgroundColour(wxColour(0, 255, 0));
        isUnderline = !isUnderline;
        while(!mrTextField.BeginUnderline());
    }
    mrTextField.SetFocus();
}