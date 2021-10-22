#include "wxIpAddressCtrl.h"


BEGIN_EVENT_TABLE(wxIpAddressCtrl,wxPanel)
//BEGIN_EVENT_TABLE(wxIpAddressCtrl,wxWindow)
	//(*EventTable(wxIpAddressCtrl)
    EVT_KEY_UP(wxIpAddressCtrl::keyReleased)
    //*)
END_EVENT_TABLE()


wxIpAddressCtrl::wxIpAddressCtrl(wxFrame* parent, wxString strText,
                    const wxPoint& pos,
                    const wxSize& size) :
  wxTextCtrl(parent, wxID_ANY)
{
    m_ptPosition = pos;
    m_siSize = size;
    SetMinSize(m_siSize);

    m_strText = strText;
    FormatOutput();
    SetMinSize(m_siSize);
    SetPosition(m_ptPosition);
    SetSize(m_siSize);
}   // wxIpAddressCtrl


void wxIpAddressCtrl::FormatOutput(void)
{
    int i, iLen, iPos = 0;
    wxString strNew = _("   .   .   .   ");
    wxString strSub;

    iLen = (int)m_strText.Len();
    for(i = 0; i < 3; i++)
    {
        iPos = m_strText.Find('.');
        if(iPos == -1) break;
        strSub = m_strText.Left(iPos);
        strNew.replace((i * 4) + 3 - iPos, iPos, strSub);
        m_strText = m_strText.Right(iLen - iPos - 1);
        iLen -= (iPos + 1);
    }
    strNew.replace((i * 4) + 3 - iLen, iLen, m_strText);
    m_strText = strNew;
    SetValue(m_strText);
}   // FormatOutput


void wxIpAddressCtrl::CheckInput(void)
{
    bool bErr = false;
    int i, j, iLen, iVal, iCh, iPos = 0;
    long lSelectFrom, lSelectTo, lInsertionPoint;
    wxString strSub, strNew = _("");

    iLen = (int)m_strText.Len();
    for(i = 0; i < 3; i++)
    {
        iPos = m_strText.Find('.');
        if(iPos == -1) break;
        strSub = m_strText.Left(iPos);
        iVal = wxAtoi(strSub);
        if(iVal < 0 || iVal > 255) { bErr = true;   break; }
        for(j = 0; j < (int)strSub.Len(); j++)
        {
            iCh = strSub.GetChar(j);
            if((iCh < 0x30 || iCh > 0x39) && iCh != 0x20) { bErr = true;   break; }
        }
        if(bErr) break;
        strSub = wxString::Format(wxT("%3i."), iVal);
        strNew += strSub;
        m_strText = m_strText.Right(iLen - iPos - 1);
        iLen -= (iPos + 1);
    }
    iVal = wxAtoi(m_strText);
    if(iVal < 0 || iVal > 255) bErr = true;
    else
    {
        for(j = 0; j < (int)m_strText.Len(); j++)
        {
            iCh = m_strText.GetChar(j);
            if((iCh < 0x30 || iCh > 0x39) && iCh != 0x20) { bErr = true;   break; }
        }
    }
    if(!bErr) { strSub = wxString::Format(wxT("%3i"), iVal);   strNew += strSub; }

    if(m_iKey >= 0x30 && m_iKey <= 0x39)
    {
        if(m_lInsertionPoint <= 4)
        {
            strSub = strNew.Mid(0, 3);
            lInsertionPoint = 3;
        }
        else if(m_lInsertionPoint <= 8)
        {
            strSub = strNew.Mid(4, 3);
            lInsertionPoint = 7;
        }
        else if(m_lInsertionPoint <= 12)
        {
            strSub = strNew.Mid(8, 3);
            lInsertionPoint = 11;
        }
        else if(m_lInsertionPoint <= 16)
        {
            strSub = strNew.Mid(12, 3);
            lInsertionPoint = 15;
        }

        iVal = wxAtoi(strSub);
        if(iVal < 100)
        {
            m_lInsertionPoint = lInsertionPoint;
            iVal = wxAtoi(strSub);
            if(iVal > 100) m_lInsertionPoint++;
        }
        SetSelection(0, 0);
    }
    if(m_lInsertionPoint > 15) m_lInsertionPoint = 15;
    m_strText = strNew;
    GetSelection(&lSelectFrom, &lSelectTo);
    SetValue(m_strText);   SetInsertionPoint(m_lInsertionPoint);
    if(lSelectFrom != 0 || lSelectTo != 0) SetSelection(lSelectFrom, lSelectTo);
}   // CheckInput


void wxIpAddressCtrl::keyReleased(wxKeyEvent& event)
{
    m_iKey = event.GetKeyCode();
    m_lInsertionPoint = GetInsertionPoint();
    m_strText = GetValue();
    CheckInput();
}   // keyReleased
