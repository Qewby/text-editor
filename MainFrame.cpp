#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_OPEN, MainFrame::OnMenuFileOpen)
    EVT_MENU(wxID_SAVE, MainFrame::OnMenuFileSave)
    EVT_MENU(wxID_EXIT, MainFrame::OnMenuFileQuit)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(NULL, TEXT_FIELD_ID, title, wxPoint(xPos, yPos), wxSize(width, height))
{
    //Handler for load and saving
    wxRichTextBuffer::AddHandler(new wxRichTextXMLHandler);

    //Menu bar
    mpMenuBar = new wxMenuBar();

    mpFileMenu = new wxMenu();
    mpFileMenu->Append(wxID_OPEN, _T("&Open"));
    mpFileMenu->Append(wxID_SAVE, _T("&Save"));
    mpFileMenu->Append(wxID_SAVEAS, _T("&Save as"));
    mpFileMenu->Append(wxID_EXIT, _T("&Quit"));
    mpMenuBar->Append(mpFileMenu, _T("&File"));

    SetMenuBar(mpMenuBar);

    //Window widgets
    mpTextField = new wxRichTextCtrl(this, wxID_ANY, wxEmptyString,
                                                     wxPoint(0, 50), wxSize(width, height));
    mpInstrumentPanel = new InstrumentPanel(this, *mpTextField, width);

    wxBoxSizer *pMainSizer = new wxBoxSizer(wxVERTICAL);
    pMainSizer->Add(mpInstrumentPanel, 1, wxEXPAND);
    pMainSizer->Add(mpTextField, 15, wxEXPAND);

    SetSizer(pMainSizer);

    mpTextField->Bind(wxEVT_RICHTEXT_LEFT_CLICK, &MainFrame::OnUpdate, this);
    mpTextField->Bind(wxEVT_RICHTEXT_CHARACTER, &MainFrame::OnUpdate, this);

    mpTextField->SetFocus();
}

void MainFrame::OnMenuFileOpen(wxCommandEvent &event)
{
    wxFileDialog *OpenDialog= new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.xml"), wxFD_OPEN);
    if ( OpenDialog->ShowModal() == wxID_OK )
    {
        mpTextField->LoadFile(OpenDialog->GetPath(), wxRICHTEXT_TYPE_XML);
    }
    OpenDialog->Close(); // Or OpenDialog->Destroy() ?
}

void MainFrame::OnMenuFileSave(wxCommandEvent &event)
{
    wxFileDialog *SaveDialog= new wxFileDialog(this, _T("Choose a file"), _(""), _("unnamed"), _("*.xml"), wxFD_SAVE);
    if (SaveDialog->ShowModal() == wxID_OK)
    {
        wxString name = SaveDialog->GetPath();
        if (!name.Contains(".xml")) name += ".xml";
        mpTextField->SaveFile(name, wxRICHTEXT_TYPE_XML);
    }
    SaveDialog->Close();
}

void MainFrame::OnMenuFileQuit(wxCommandEvent &event)
{
    Close(false);
}

void MainFrame::OnUpdate(wxRichTextEvent &event) {
    mpInstrumentPanel->Update();
}