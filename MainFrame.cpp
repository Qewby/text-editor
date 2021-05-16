#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(NULL, -1, title, wxPoint(xPos, yPos), wxSize(width, height))
{

}