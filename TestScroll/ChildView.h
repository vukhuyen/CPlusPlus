// Filename: ChildView.h.
// S.Chan, 02 Jul 2005

#pragma once

// CChildView window.
class CChildView : public CWnd
{
public:
    CChildView();
    virtual ~CChildView();

protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

    // Generated message map functions.
    afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnPaint();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    DECLARE_MESSAGE_MAP()

private:
    // This is either a CScrollWnd or CScrollDlg.
    CWnd* m_scrollWin;
};

// END

