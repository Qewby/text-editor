#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_OPEN, MainFrame::OnMenuFileOpen)
    EVT_MENU(wxID_SAVE, MainFrame::OnMenuFileSave)
    EVT_MENU(wxID_SAVEAS, MainFrame::OnMenuFileSaveAs)
    EVT_MENU(wxID_EXIT, MainFrame::OnMenuFileQuit)

    EVT_MENU(wxID_UNDO, MainFrame::OnMenuEditUndo)
    EVT_MENU(wxID_REDO, MainFrame::OnMenuEditRedo)

    EVT_MENU(wxID_COPY, MainFrame::OnMenuEditCopy)
    EVT_MENU(wxID_CUT, MainFrame::OnMenuEditCut)
    EVT_MENU(wxID_PASTE, MainFrame::OnMenuEditPaste)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(NULL, TEXT_FIELD_ID, title, wxPoint(xPos, yPos), wxSize(width, height))
{
    //Handler for load and saving
    wxRichTextBuffer::AddHandler(new wxRichTextXMLHandler);

    fileName = wxEmptyString;

    //Menu bar
    mpMenuBar = new wxMenuBar();

    //File menu
    mpFileMenu = new wxMenu();
    mpFileMenu->Append(wxID_OPEN, _T("&Open"));
    mpFileMenu->Append(wxID_SAVE, _T("&Save"));
    mpFileMenu->Append(wxID_SAVEAS, _T("&Save as"));
    mpFileMenu->Append(wxID_EXIT, _T("&Quit"));
    mpMenuBar->Append(mpFileMenu, _T("File"));

    //Edit menu
    mpEditMenu = new wxMenu();
    mpEditMenu->Append(wxID_UNDO, _T("&Undo"));
    mpEditMenu->Append(wxID_REDO, _T("&Redo"));
    mpEditMenu->AppendSeparator();
    mpEditMenu->Append(wxID_COPY, _T("&Copy"));
    mpEditMenu->Append(wxID_CUT, _T("&Cut"));
    mpEditMenu->Append(wxID_PASTE, _T("&Paste"));
    mpMenuBar->Append(mpEditMenu, _T("Edit"));
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
        fileName = OpenDialog->GetPath();
        mpTextField->LoadFile(fileName, wxRICHTEXT_TYPE_XML);
    }
    OpenDialog->Close();
}

void MainFrame::OnMenuFileSave(wxCommandEvent &event)
{
    if (fileName == wxEmptyString) {
        OnMenuFileSaveAs(event);
    }
    else {
        mpTextField->SaveFile(fileName, wxRICHTEXT_TYPE_XML);
    }
}

void MainFrame::OnMenuFileSaveAs(wxCommandEvent &event)
{
    wxFileDialog *SaveDialog= new wxFileDialog(this, _T("Choose a file"), _(""), _("unnamed"), _("*.xml"), wxFD_SAVE);
    if (SaveDialog->ShowModal() == wxID_OK)
    {
        fileName = SaveDialog->GetPath();
        if (!fileName.Contains(".xml")) fileName += ".xml";
        mpTextField->SaveFile(fileName, wxRICHTEXT_TYPE_XML);
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

void MainFrame::OnMenuEditCopy(wxCommandEvent &event) {
    mpTextField->Copy();
}

void MainFrame::OnMenuEditCut(wxCommandEvent &event) {
    mpTextField->Cut();
    mpInstrumentPanel->Update();
}

void MainFrame::OnMenuEditPaste(wxCommandEvent &event) {
    mpTextField->Paste();
    mpInstrumentPanel->Update();
}

void MainFrame::OnMenuEditUndo(wxCommandEvent &event) {
    mpTextField->Undo();
    mpInstrumentPanel->Update();
}

void MainFrame::OnMenuEditRedo(wxCommandEvent &event) {
    mpTextField->Redo();
    mpInstrumentPanel->Update();
}