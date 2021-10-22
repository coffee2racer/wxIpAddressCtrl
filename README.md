# wxIpAddressCtrl (C++ / wxWidgets)
C++ Custom IpAddressCtrl for wxWidgets demonstrated inside a Code::Blocks sample project

<b>Introduction</b></br>
The wxIpAddressCtrl widget is derived from wxTextCtrl and testet on</br>
    • a Raspberry pi with Raspberry OS</br>
    • a Odroid N2 with Ubuntu 20.04 (arm64-CPU)</br>
    • Debian Linux 64 bit</br>
    
<b>Using the code</b></br>
    • Copy the files “wxIpAddressCtrl.h” and “wxIpAddressCtrl.cpp” into your project directory.</br>
    • Include “wxIpAddressCtrl.h” into the header file of your dialog or frame window.</br>
    • Make a declaration for the pointer to the control class in the header file of your dialog or frame window,</br>
      i.e: wxIpAddressCtrl* IpAddressInput;</br>
    • Create the control with an initialization string:</br>
      IpAddressInput = new wxIpAddressCtrl(this, _("10.12.0.1"), wxPoint(120,32), wxSize(128,24));</br>

The “Show”-Button demonstrates how to use some native functions from parent class.

<b>What happens in wxIpAddrCtrl.h</b></br>
    • Declaration of the class “wxIpAddressCtrl” derived from the wxWidgets native class “wxTextCtrl”.</br>
    • Declaration of a wxKeyEvent function:</br>void keyReleased(wxKeyEvent& event);</br>
    • Declaration of some functions and variables</br>

<b>What happens in wxIpAddrCtrl.cpp</b></br>
    • Activate the event EVT_KEY_UP which call the “keyReleased” function.</br>
    • Initalization of the wxIpAdressCtrl class in the constructor.</br>
    • Write the formatted output to the control.</br>
    • Check the input chars and handle them.</br>
