#ifndef WXIPADDRESSCTRL_H
#define WXIPADDRESSCTRL_H

#include <wx/wx.h>


class wxIpAddressCtrl : public wxTextCtrl
{
    public:
        wxIpAddressCtrl(wxFrame* parent, wxString strText,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize);

        void keyReleased(wxKeyEvent& event);


        void FormatOutput(void);
        void CheckInput(void);

        DECLARE_EVENT_TABLE()

    protected:
        wxString m_strText;
        wxPoint m_ptPosition;
        wxSize m_siSize;

    private:
        int m_iKey;
        long m_lInsertionPoint;
};

#endif // WXIPADDRESSCTRL_H
