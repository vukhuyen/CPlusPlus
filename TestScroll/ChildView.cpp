// Filename: ChildView.cpp
// S.Chan, 02 Jul 2005

#include "stdafx.h"
#include "TestScroll.h"
#include "ChildView.h"
#include "ScrollWnd.h"
#include "ScrollDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CChildView, CWnd)
    ON_WM_CREATE()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()
    ON_WM_SIZE()
END_MESSAGE_MAP()

CChildView::CChildView()
{
    m_scrollWin = NULL;
}

CChildView::~CChildView()
{
}

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
    if (!CWnd::PreCreateWindow(cs))
        return FALSE;

    cs.dwExStyle |= WS_EX_CLIENTEDGE;
    cs.style &= ~WS_BORDER;
    cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
        ::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

    return TRUE;
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if ( CWnd::OnCreate(lpCreateStruct) == -1 )
        return -1;

    // We either create a CScrollWnd or a CScrollDlg.
    // We alternate using a counter.
    static int counter = 0;

    if ( counter % 2 == 0 )
        m_scrollWin = new CScrollWnd(this);
    else
        m_scrollWin = new CScrollDlg(this);
    ++counter;

    return 0;
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
    // Return TRUE to indicate further erasing is not needed.
    return TRUE;
}

void CChildView::OnPaint() 
{
    CPaintDC dc(this); // device context for painting

    // TODO: Add your message handler code here

    // Do not call CWnd::OnPaint() for painting messages
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);

    CRect rect;
    GetClientRect(&rect);

    // Resize and reposition the scrolling window.
    if ( m_scrollWin != NULL && ::IsWindow(m_scrollWin->m_hWnd) )
    {
        m_scrollWin->SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(),
            SWP_NOZORDER | SWP_NOACTIVATE);
    }
}

// END

