/***************************************************************
 * Name:      IpAddressCtrlApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Helmut Nebauer (helmut.nebauer@tecia.de)
 * Created:   2021-10-07
 * Copyright: Helmut Nebauer (www.tecia.de)
 * License:
 **************************************************************/

#include "IpAddressCtrlApp.h"

//(*AppHeaders
#include "IpAddressCtrlMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(IpAddressCtrlApp);

bool IpAddressCtrlApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	IpAddressCtrlFrame* Frame = new IpAddressCtrlFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
