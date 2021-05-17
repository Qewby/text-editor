#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_OPEN, MainFrame::OnMenuFileOpen)
    EVT_MENU(wxID_SAVE, MainFrame::OnMenuFileSave)
    EVT_MENU(wxID_EXIT, MainFrame::OnMenuFileQuit)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(NULL, -1, title, wxPoint(xPos, yPos), wxSize(width, height))
{
    //Handler for load and saving
    wxRichTextBuffer::AddHandler(new wxRichTextXMLHandler);


    mpMenuBar = new wxMenuBar();

    mpFileMenu = new wxMenu();
    mpFileMenu->Append(wxID_OPEN, _T("&Open"));
    mpFileMenu->Append(wxID_SAVE, _T("&Save"));
    mpFileMenu->Append(wxID_SAVEAS, _T("&Save as"));
    mpFileMenu->Append(wxID_EXIT, _T("&Quit"));
    mpMenuBar->Append(mpFileMenu, _T("&File"));

    SetMenuBar(mpMenuBar);

    mpTextField = new wxRichTextCtrl(this, wxID_ANY, wxEmptyString,
                                                     wxDefaultPosition, wxDefaultSize);
    mpTextField->BeginSuppressUndo();
    mpTextField->BeginParagraphSpacing(0, 20);
    mpTextField->BeginAlignment(wxTEXT_ALIGNMENT_CENTRE);
    mpTextField->BeginBold();
    mpTextField->BeginFontSize(14);
    mpTextField->WriteText(wxT("Welcome to wxRichTextCtrl, a wxWidgets control for editing and presenting styled text and images"));
    mpTextField->EndFontSize();
    mpTextField->Newline();
    mpTextField->BeginItalic();
    mpTextField->WriteText(wxT("by Julian Smart"));
    mpTextField->EndItalic();
    mpTextField->EndBold();
    mpTextField->Newline();
    mpTextField->EndAlignment();
    mpTextField->Newline();
    mpTextField->Newline();
    mpTextField->WriteText(wxT("What can you do with this thing? "));
    mpTextField->WriteText(wxT(" Well, you can change text "));
    mpTextField->BeginTextColour(wxColour(255, 0, 0));
    mpTextField->WriteText(wxT("colour, like this red bit."));
    mpTextField->EndTextColour();
    mpTextField->BeginTextColour(wxColour(0, 0, 255));
    mpTextField->WriteText(wxT(" And this blue bit."));
    mpTextField->EndTextColour();
    mpTextField->WriteText(wxT(" Naturally you can make things "));
    mpTextField->BeginBold();
    mpTextField->WriteText(wxT("bold "));
    mpTextField->EndBold();
    mpTextField->BeginItalic();
    mpTextField->WriteText(wxT("or italic "));
    mpTextField->EndItalic();
    mpTextField->BeginUnderline();
    mpTextField->WriteText(wxT("or underlined."));
    mpTextField->EndUnderline();
    mpTextField->BeginFontSize(14);
    mpTextField->WriteText(wxT(" Different font sizes on the same line is allowed, too."));
    mpTextField->EndFontSize();
    mpTextField->WriteText(wxT(" Next we'll show an indented paragraph."));
    mpTextField->BeginLeftIndent(60);
    mpTextField->Newline();
    mpTextField->WriteText(wxT("Indented paragraph."));
    mpTextField->EndLeftIndent();
    mpTextField->Newline();
    mpTextField->WriteText(wxT("Next, we'll show a first-line indent, achieved using BeginLeftIndent(100, -40)."));
    mpTextField->BeginLeftIndent(100, -40);
    mpTextField->Newline();
    mpTextField->WriteText(wxT("It was in January, the most down-trodden month of an Edinburgh wintepTextField->"));
    mpTextField->EndLeftIndent();
    mpTextField->Newline();
    mpTextField->WriteText(wxT("Numbered bullets are possible, again using subindents:"));
    mpTextField->BeginNumberedBullet(1, 100, 60);
    mpTextField->Newline();
    mpTextField->WriteText(wxT("This is my first item. Note that wxRichTextCtrl doesn't automatically do numbering, but this will be added latepTextField->"));
    mpTextField->EndNumberedBullet();
    mpTextField->BeginNumberedBullet(2, 100, 60);
    mpTextField->Newline();
    mpTextField->WriteText(wxT("This is my second item."));
    mpTextField->EndNumberedBullet();
    mpTextField->Newline();
    mpTextField->WriteText(wxT("The following paragraph is right-indented:"));
    mpTextField->BeginRightIndent(200);
    mpTextField->Newline();
    mpTextField->WriteText(wxT("It was in January, the most down-trodden month of an Edinburgh wintepTextField-> An attractive woman came into the cafe, which is nothing remarkable."));
    mpTextField->EndRightIndent();
    mpTextField->Newline();
    wxArrayInt tabs;
    tabs.Add(400);
    tabs.Add(600);
    tabs.Add(800);
    tabs.Add(1000);
    wxTextAttr attr;
    mpTextField->SetDefaultStyle(attr);
    mpTextField->WriteText(wxT("This line contains tabs:\tFirst tab\tSecond tab\tThird tab"));
    mpTextField->Newline();
    mpTextField->WriteText(wxT("Other notable features of wxRichTextCtrl include:"));
    mpTextField->BeginSymbolBullet(wxT('*'), 100, 60);
    mpTextField->Newline();
    mpTextField->WriteText(wxT("Compatibility with wxTextCtrl API"));
    mpTextField->EndSymbolBullet();
    mpTextField->WriteText(wxT("Note: this sample content was generated programmatically from within the MyFrame constructor in the demo. The images were loaded from inline XPMs. Enjoy wxRichTextCtrl!"));
    mpTextField->EndSuppressUndo();
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