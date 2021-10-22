/***************************************************************
 * Name:      IpAddressCtrlMain.h
 * Purpose:   Defines Application Frame
 * Author:    Helmut Nebauer (helmut.nebauer@tecia.de)
 * Created:   2021-10-07
 * Copyright: Helmut Nebauer (www.tecia.de)
 * License:
 **************************************************************/

#ifndef IPADDRESSCTRLMAIN_H
#define IPADDRESSCTRLMAIN_H

//(*Headers(IpAddressCtrlFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)
#include "wxIpAddressCtrl.h"

class IpAddressCtrlFrame: public wxFrame
{
    public:

        IpAddressCtrlFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~IpAddressCtrlFrame();

    private:

        //(*Handlers(IpAddressCtrlFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBtnShowClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(IpAddressCtrlFrame)
        static const long ID_BTN_QUIT;
        static const long ID_BTN_SHOW;
        static const long ID_STXT_IP_ADDRESS;
        static const long ID_STXT_IP_ADDRESS_MIRROR;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(IpAddressCtrlFrame)
        wxButton* BtnQuit;
        wxButton* BtnShow;
        wxStaticText* StxtIpAddress;
        wxStaticText* StxtIpAddressMirror;
        wxStatusBar* StatusBar1;
        //*)
        wxIpAddressCtrl* IpAddressField;

        DECLARE_EVENT_TABLE()
};

#endif // IPADDRESSCTRLMAIN_H
