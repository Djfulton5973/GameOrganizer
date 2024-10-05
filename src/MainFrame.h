
#include <wx/wx.h>


class App : public wxApp
{
    public:
    //Startup
    virtual bool OnInit();
};

DECLARE_APP(App)

//Creates an App object
IMPLEMENT_APP(App)

class MainFrame : public wxFrame
{
    public:

    //constructor
    MainFrame(const wxString& title);

    //event handlers
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    private:

    //handles the events
    DECLARE_EVENT_TABLE()

};