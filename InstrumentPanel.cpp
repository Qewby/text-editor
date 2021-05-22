#include "InstrumentPanel.h"

BEGIN_EVENT_TABLE(InstrumentPanel, wxPanel)
    EVT_BUTTON(wxID_BOLD, InstrumentPanel::OnBoldButton)
END_EVENT_TABLE()

InstrumentPanel::InstrumentPanel(wxWindow *parent, wxRichTextCtrl& textField)
    : mrTextField(textField), wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(800, 50))
    {
    wxBoxSizer *pSizer = new wxBoxSizer(wxHORIZONTAL);
    mpBoldButton = new wxButton(this, wxID_BOLD, _T(""), wxPoint(0, 0), wxSize(50, 100));
    pSizer->Add(mpBoldButton);

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