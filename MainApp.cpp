#include "MainApp.h"

IMPLEMENT_APP(MainApp)

bool MainApp::OnInit() {
    MainFrame *pWindow = new MainFrame(_T("Window"), 0, 0, 800, 500);
    pWindow->Show(true);
    SetTopWindow(pWindow);

    return true;
}
