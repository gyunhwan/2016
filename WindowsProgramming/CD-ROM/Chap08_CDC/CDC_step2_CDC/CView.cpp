#include <windows.h>
#include <math.h>
#include "stdafx.h"
#include "CView.h"
#include "DC.h"

CView app;

//{{AFX_MESSAGE
BEGIN_MESSAGE_MAP(CView)
    {WM_CREATE,&CView::OnCreate},
    {WM_PAINT,&CView::OnDraw},
    {WM_DESTROY,&CView::OnDestroy},
    //{{seojt
    {WM_SIZE,&CView::OnSize},
    {WM_LBUTTONDOWN,&CView::OnLButtonDown},
    //}}seojt
END_MESSAGE_MAP()
//}}AFX_MESSAGE

LRESULT CView::OnCreate(WPARAM wParam,LPARAM lParam) {
    return 0L;
}//CView::OnCreate

LRESULT CView::OnDraw(WPARAM wParam,LPARAM lParam) {
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;

    hdc = BeginPaint(hwnd,&ps);
    GetClientRect(hwnd,&rect);
    DrawText(hdc,"Hello, Windows!",-1,&rect,
        DT_SINGLELINE|DT_CENTER|DT_VCENTER);
    EndPaint(hwnd,&ps);
    return 0L;
}//CView::OnDraw

LRESULT CView::OnDestroy(WPARAM wParam,LPARAM lParam) {
    PostQuitMessage(0);
    return 0L;
}//CView::OnDestroy

//{{seojt
LRESULT CView::OnLButtonDown(WPARAM wParam,LPARAM lParam) {
    CDC dc(this);
    int i;

    dc.MoveToEx (0, cyClient / 2, NULL) ;
    dc.LineTo(cxClient, cyClient / 2) ;

    for (i = 0 ; i < NUM ; i++) {
        pt[i].x = i * cxClient / NUM ;
        pt[i].y = (int) (cyClient / 2 *
            (1 - sin (TWOPI * i / NUM))) ;
    }//for
    dc.Polyline (pt, NUM) ;
    
    return 0L;
}//CView::OnLButtonDown
//}}seojt

//{{seojt
LRESULT CView::OnSize(WPARAM wParam,LPARAM lParam) {
    cxClient = LOWORD(lParam);
    cyClient = HIWORD(lParam);
    return 0L;
}//CView::OnSize
//}}seojt