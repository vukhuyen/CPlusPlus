// Filename: ScrollWnd.h
// 2005-07-02 nschan Initial revision.
// 2005-09-08 nschan Use memory DC drawing to eliminate flickering on resize.

#ifndef SCROLL_WND_INCLUDED
#define SCROLL_WND_INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Forward class declarations.
class CScrollHelper;

// CScrollWnd implements a scrollable window using CScrollHelper.
class CScrollWnd : public CWnd
{
public:
    CScrollWnd(CWnd* parentWnd);
    virtual ~CScrollWnd();

protected:
    // ClassWizard generated virtual function overrides.
    //{{AFX_VIRTUAL(CScrollWnd)
    virtual void PostNcDestroy();
    //}}AFX_VIRTUAL

    // Generated message map functions.
    //{{AFX_MSG(CScrollWnd)
    afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg int  OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
    afx_msg void OnPaint();
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

private:
    void DrawScrollInfo(CDC* pDC);

    CScrollHelper* m_scrollHelper;
};

#endif // SCROLL_WND_INCLUDED

// END

