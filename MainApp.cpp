#include "MainApp.h"

IMPLEMENT_APP(MainApp)

bool MainApp::OnInit() {
    MainFrame *window = new MainFrame(_T("Window"), 0, 0, 800, 500);
    window->Show(true);
    SetTopWindow(window);

    return true;
}
