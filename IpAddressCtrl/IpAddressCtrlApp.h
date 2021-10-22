/***************************************************************
 * Name:      IpAddressCtrlApp.h
 * Purpose:   Defines Application Class
 * Author:    Helmut Nebauer (helmut.nebauer@tecia.de)
 * Created:   2021-10-07
 * Copyright: Helmut Nebauer (www.tecia.de)
 * License:
 **************************************************************/

#ifndef IPADDRESSCTRLAPP_H
#define IPADDRESSCTRLAPP_H

#include <wx/app.h>

class IpAddressCtrlApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // IPADDRESSCTRLAPP_H
