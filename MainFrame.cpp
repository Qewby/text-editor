#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(NULL, -1, title, wxPoint(xPos, yPos), wxSize(width, height))
{
    mpMenuBar = new wxMenuBar();

    mpFileMenu = new wxMenu();
    mpFileMenu->Append(wxID_OPEN, _T("&Open"));
    mpFileMenu->Append(wxID_SAVE, _T("&Save"));
    mpFileMenu->Append(wxID_SAVEAS, _T("&Save as"));
    mpFileMenu->Append(wxID_EXIT, _T("&Quit"));
    mpMenuBar->Append(mpFileMenu, _T("&File"));

    SetMenuBar(mpMenuBar);
}