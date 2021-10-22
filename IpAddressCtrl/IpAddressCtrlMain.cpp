/***************************************************************
 * Name:      IpAddressCtrlMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Helmut Nebauer (helmut.nebauer@tecia.de)
 * Created:   2021-10-07
 * Copyright: Helmut Nebauer (www.tecia.de)
 * License:
 **************************************************************/

#include "IpAddressCtrlMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(IpAddressCtrlFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(IpAddressCtrlFrame)
const long IpAddressCtrlFrame::ID_BTN_QUIT = wxNewId();
const long IpAddressCtrlFrame::ID_BTN_SHOW = wxNewId();
const long IpAddressCtrlFrame::ID_STXT_IP_ADDRESS = wxNewId();
const long IpAddressCtrlFrame::ID_STXT_IP_ADDRESS_MIRROR = wxNewId();
const long IpAddressCtrlFrame::idMenuQuit = wxNewId();
const long IpAddressCtrlFrame::idMenuAbout = wxNewId();
const long IpAddressCtrlFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(IpAddressCtrlFrame,wxFrame)
    //(*EventTable(IpAddressCtrlFrame)
    //*)
END_EVENT_TABLE()

IpAddressCtrlFrame::IpAddressCtrlFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(IpAddressCtrlFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("wxIpAddressCtrl"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(295,206));
    BtnQuit = new wxButton(this, ID_BTN_QUIT, _("Quit"), wxPoint(160,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_QUIT"));
    BtnShow = new wxButton(this, ID_BTN_SHOW, _("Show"), wxPoint(48,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_SHOW"));
    StxtIpAddress = new wxStaticText(this, ID_STXT_IP_ADDRESS, _("IP Address:"), wxPoint(12,32), wxDefaultSize, 0, _T("ID_STXT_IP_ADDRESS"));
    StxtIpAddressMirror = new wxStaticText(this, ID_STXT_IP_ADDRESS_MIRROR, wxEmptyString, wxPoint(120,72), wxSize(128,17), 0, _T("ID_STXT_IP_ADDRESS_MIRROR"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_BTN_QUIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&IpAddressCtrlFrame::OnQuit);
    Connect(ID_BTN_SHOW,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&IpAddressCtrlFrame::OnBtnShowClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&IpAddressCtrlFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&IpAddressCtrlFrame::OnAbout);
    //*)

    IpAddressField = new wxIpAddressCtrl(this, _("10.12.0.1"), wxPoint(120,32), wxSize(128,24));
}

IpAddressCtrlFrame::~IpAddressCtrlFrame()
{
    //(*Destroy(IpAddressCtrlFrame)
    //*)
}

void IpAddressCtrlFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void IpAddressCtrlFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

// Show and test some derived functions
void IpAddressCtrlFrame::OnBtnShowClick(wxCommandEvent& event)
{
    wxString str;

    str = IpAddressField->GetValue();
    IpAddressField->SetValue(str);
    StxtIpAddressMirror->SetLabel(str);
}
