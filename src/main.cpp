#include "MainFrame.h"
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

bool App::OnInit()
{
    //Creates the main window
    MainFrame *frame = new MainFrame("Minimal wxWidgets App");

    //Initial client dimensions
    frame->SetClientSize(800, 600);

    //Centers the application
    frame->Center();

    //Have to implement this line to show it
    frame->Show(true);

    //Starts the loop
    return true;
};

//Event table for MainFrame
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
    EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
         : wxFrame(NULL, wxID_ANY, title)
{
    //Set the frame icon
    wxIcon icon("E:\\Mod manager\\GameOrganizer\\src\\favicon.ico", wxBITMAP_TYPE_ICO);
    SetIcon(wxIcon(icon));

    //Create a menu bar
    wxMenu *fileMenu = new wxMenu;

    //Placing the about item under the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, "&About...\tF1",
                     "Show about dialog");

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X",
                     "Quit this program");

    //Appends the menu to the menu bar
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");

    //Attach the menu to the frame
    SetMenuBar(menuBar);

    //Status bar
    CreateStatusBar(2);
    SetStatusText("Welcome to wxWidgets!");
};

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf("Hello and welcome to %s",
    wxVERSION_STRING);

    wxMessageBox(msg, "About Minimal",
    wxOK | wxICON_INFORMATION, this);
};

void MainFrame::OnQuit(wxCommandEvent& event)
{
    //Clears the frame, ends the application
    Close();
};