// TestScroll.h : main header file for the TESTSCROLL application
//

#if !defined(AFX_TESTSCROLL_H__53A68F7F_5A82_4976_B78E_8115A9E52364__INCLUDED_)
#define AFX_TESTSCROLL_H__53A68F7F_5A82_4976_B78E_8115A9E52364__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestScrollApp:
// See TestScroll.cpp for the implementation of this class
//

class CTestScrollApp : public CWinApp
{
public:
	CTestScrollApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestScrollApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HMENU m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	//{{AFX_MSG(CTestScrollApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSCROLL_H__53A68F7F_5A82_4976_B78E_8115A9E52364__INCLUDED_)
