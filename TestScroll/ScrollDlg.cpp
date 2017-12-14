// Filename: ScrollDlg.cpp
// S.Chan, 03 Jul 2005

#include "stdafx.h"
#include "ScrollDlg.h"
#include "ScrollHelper.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CScrollDlg, CDialog)
    //{{AFX_MSG_MAP(CScrollDlg)
    ON_WM_MOUSEACTIVATE()
    ON_WM_PAINT()
    ON_WM_HSCROLL()
    ON_WM_VSCROLL()
    ON_WM_MOUSEWHEEL()
    ON_WM_SIZE()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CScrollDlg::CScrollDlg(CWnd* pParent)
    : CDialog(IDD_SCROLL_DLG, pParent)
{
    m_isInit = false;

    // Create the scroll helper and attach it to this dialog.
    m_scrollHelper = new CScrollHelper;
    m_scrollHelper->AttachWnd(this);

    // We also set the display size equal to the dialog size.
    // This is the size of the dialog in pixels as laid out
    // in the resource editor.
    m_scrollHelper->SetDisplaySize(701, 375);

    // Create the dialog.
    Create(IDD_SCROLL_DLG, pParent);
}

CScrollDlg::~CScrollDlg()
{
    delete m_scrollHelper;
}

void CScrollDlg::PostNcDestroy()
{
    m_scrollHelper->DetachWnd();

    // Delete the C++ instance so the parent does not have
    // to worry about it.
    delete this;
}

void CScrollDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);

    //{{AFX_DATA_MAP(CScrollDlg)
    DDX_Control(pDX, IDC_SCROLLINFO_LB, m_scrollInfoLB);
    //}}AFX_DATA_MAP
}

BOOL CScrollDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    m_isInit = true;

    DisplayScrollInfo();

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void CScrollDlg::OnOK()
{
    // Empty implementation.
}

void CScrollDlg::OnCancel()
{
    // Empty implementation.
}

int CScrollDlg::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
    int status = CDialog::OnMouseActivate(pDesktopWnd, nHitTest, message);

    // We handle this message so that when user clicks once in the
    // dialog, it will be given the focus, and this will allow
    // mousewheel messages to be directed to this window.
    SetFocus();
    DisplayScrollInfo();

    return status;
}

void CScrollDlg::OnPaint()
{
    CDialog::OnPaint();

    // Only purpose of handling OnPaint is to set the
    // caption text of the MDI child frame.
    DisplayScrollPos();
}

void CScrollDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    m_scrollHelper->OnHScroll(nSBCode, nPos, pScrollBar);

    DisplayScrollInfo();
}

void CScrollDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    m_scrollHelper->OnVScroll(nSBCode, nPos, pScrollBar);

    DisplayScrollInfo();
}

BOOL CScrollDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
    BOOL wasScrolled = m_scrollHelper->OnMouseWheel(nFlags, zDelta, pt);

    DisplayScrollInfo();

    return wasScrolled;
}

void CScrollDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialog::OnSize(nType, cx, cy);

    m_scrollHelper->OnSize(nType, cx, cy);

    DisplayScrollInfo();
}

void CScrollDlg::DisplayScrollInfo()
{
    if ( !::IsWindow(m_hWnd) )
        return;
    if ( !m_isInit )
        return;

    CString text;

    // Show the page size.
    text.Format("PageSize: %d x %d", m_scrollHelper->GetPageSize().cx, m_scrollHelper->GetPageSize().cy);
    m_scrollInfoLB.DeleteString(0);
    m_scrollInfoLB.InsertString(0, text);

    // Show the display size.
    text.Format("DisplaySize: %d x %d", m_scrollHelper->GetDisplaySize().cx, m_scrollHelper->GetDisplaySize().cy);
    m_scrollInfoLB.DeleteString(1);
    m_scrollInfoLB.InsertString(1, text);

    // Show the scroll position.
    DisplayScrollPos();

    // Show the GetClientRect() value.
    CRect rect;
    GetClientRect(&rect);
    text.Format("ClientRect(x,y,cx,cy): %d, %d, %d, %d", rect.left, rect.top, rect.Width(), rect.Height());
    m_scrollInfoLB.DeleteString(2);
    m_scrollInfoLB.InsertString(2, text);
}

void CScrollDlg::DisplayScrollPos()
{
    CString text;

    // Change the caption text of the MDI child frame window to show
    // the current scroll position.
    text.Format("TestScroll (ScrollPos: %d, %d)", m_scrollHelper->GetScrollPos().cx, m_scrollHelper->GetScrollPos().cy);
    CWnd* pWnd = GetParentFrame();
    if ( pWnd != NULL )
    {
        pWnd->SetWindowText(text);
    }
}

// END
