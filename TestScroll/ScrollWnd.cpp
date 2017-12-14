// Filename: ScrollWnd.cpp
// 2005-07-02 nschan Initial revision.
// 2005-09-08 nschan Use memory DC drawing to eliminate flickering on resize.

#include "stdafx.h"
#include "ScrollWnd.h"
#include "ScrollHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CScrollWnd, CWnd)
    //{{AFX_MSG_MAP(CScrollWnd)
    ON_WM_CREATE()
    ON_WM_ERASEBKGND()
    ON_WM_MOUSEACTIVATE()
    ON_WM_PAINT()
    ON_WM_HSCROLL()
    ON_WM_VSCROLL()
    ON_WM_MOUSEWHEEL()
    ON_WM_SIZE()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CScrollWnd::CScrollWnd(CWnd* parentWnd)
{
    // Create the scroll helper class and attach to this wnd.
    m_scrollHelper = new CScrollHelper;
    m_scrollHelper->AttachWnd(this);

    // Create the GUI window. Notice we specify the styles WS_HSCROLL
    // and WS_VSCROLL. These are needed to enable the horizontal and
    // vertical scrollbars for this window.
    Create(NULL, "CScrollWnd", WS_CHILD | WS_VISIBLE |WS_HSCROLL | WS_VSCROLL,
        CRect(0,0,0,0), parentWnd, 0, NULL);
}

CScrollWnd::~CScrollWnd()
{
    delete m_scrollHelper;
}

void CScrollWnd::PostNcDestroy()
{
    m_scrollHelper->DetachWnd();

    // Delete the C++ instance so the parent does not have
    // to worry about it.
    delete this;
}

int CScrollWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if ( CWnd::OnCreate(lpCreateStruct) == -1 )
        return -1;

    return 0;
}

BOOL CScrollWnd::OnEraseBkgnd(CDC* pDC)
{
    // Return TRUE to indicate further erasing is not needed.
    return TRUE;
}

int CScrollWnd::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
    int status = CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);

    // We handle this message so that when user clicks once in the
    // window, it will be given the focus, and this will allow
    // mousewheel messages to be directed to this window.
    SetFocus();

    return status;
}

void CScrollWnd::OnPaint()
{
    CPaintDC dc(this);

    // Get the client rect.
    CRect rect;
    GetClientRect(&rect);

    // Prepare for memory DC drawing.
    CDC memoryDC;
    if ( rect.Width() > 0 && rect.Height() > 0 &&
         memoryDC.CreateCompatibleDC(&dc) )
    {
        CBitmap bitmap;
        if ( bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height()) )
        {
            CDC* pDC = &memoryDC;

            // Select bitmap into memory DC.
            CBitmap* pOldBitmap = pDC->SelectObject(&bitmap);

            // Set up the memory DC for drawing graphics and text.
            CPen pen(PS_SOLID, 1, RGB(0,0,255));
            CPen* pOldPen = pDC->SelectObject(&pen);
            CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
            COLORREF oldTextColor = pDC->SetTextColor(RGB(0,0,255));
            int oldBkMode = pDC->SetBkMode(TRANSPARENT);

            // Fill the background.
            pDC->FillSolidRect(&rect, RGB(0,255,0));

            // Draw a rectangle representing the display size.
            // The rectangle needs to be offset due to scrolling position.
            CRect dispRect;
            dispRect.SetRect(0, 0,
                             m_scrollHelper->GetDisplaySize().cx,
                             m_scrollHelper->GetDisplaySize().cy);
            dispRect.OffsetRect(-m_scrollHelper->GetScrollPos().cx,
                                -m_scrollHelper->GetScrollPos().cy);
            pDC->Rectangle(&dispRect);

            // Draw text information.
            DrawScrollInfo(pDC);

            // Do the bitblt.
            dc.BitBlt(0, 0, rect.Width(), rect.Height(),
                      pDC, 0, 0, SRCCOPY);

            // Restore DC state.
            pDC->SetBkMode(oldBkMode);
            pDC->SetTextColor(oldTextColor);
            pDC->SelectObject(pOldBrush);
            pDC->SelectObject(pOldPen);
            pDC->SelectObject(pOldBitmap);
        }
    }
}

void CScrollWnd::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    m_scrollHelper->OnHScroll(nSBCode, nPos, pScrollBar);
}

void CScrollWnd::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    m_scrollHelper->OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CScrollWnd::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
    BOOL wasScrolled = m_scrollHelper->OnMouseWheel(nFlags, zDelta, pt);
    return wasScrolled;
}

void CScrollWnd::OnSize(UINT nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);

    CRect rect;
    GetWindowRect(&rect);

    // Initialization: Set the display size if needed.
    if ( m_scrollHelper->GetDisplaySize() == CSize(0,0) )
    {
        if ( rect.Width() > 0 && rect.Height() > 0 )
            m_scrollHelper->SetDisplaySize(rect.Width(), rect.Height());
    }

    m_scrollHelper->OnSize(nType, cx, cy);
}

void CScrollWnd::DrawScrollInfo(CDC* pDC)
{
    int x = 3, y = 2;

    // Offset starting position due to scrolling.
    x -= m_scrollHelper->GetScrollPos().cx;
    y -= m_scrollHelper->GetScrollPos().cy;

    // Draw the page size.
    CString text;
    text.Format("PageSize: %d x %d", m_scrollHelper->GetPageSize().cx, m_scrollHelper->GetPageSize().cy);
    pDC->TextOut(x, y, text);

    // Draw the display size.
    y += 16;
    text.Format("DisplaySize: %d x %d", m_scrollHelper->GetDisplaySize().cx, m_scrollHelper->GetDisplaySize().cy);
    pDC->TextOut(x, y, text);

    // Change the caption text of the MDI child frame window to show
    // the current scroll position.
    text.Format("TestScroll (ScrollPos: %d, %d)", m_scrollHelper->GetScrollPos().cx, m_scrollHelper->GetScrollPos().cy);
    CWnd* pWnd = GetParentFrame();
    if ( pWnd != NULL )
    {
        pWnd->SetWindowText(text);
    }

    // Draw the GetClientRect() value.
    CRect rect;
    GetClientRect(&rect);
    y += 16;
    text.Format("ClientRect(x,y,cx,cy): %d, %d, %d, %d", rect.left, rect.top, rect.Width(), rect.Height());
    pDC->TextOut(x, y, text);
}

// END
