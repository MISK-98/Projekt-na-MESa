﻿
// ChildFrm.cpp: implementacja klasy CChildFrame
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// Tworzenie/niszczenie obiektu CChildFrame

CChildFrame::CChildFrame() noexcept
{
	// TODO: dodaj tutaj kod inicjowania elementu członkowskiego
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: zmodyfikuj klasę Window lub style w tym miejscu, modyfikując klasę CREATESTRUCT
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// Diagnostyka elementu CChildFrame

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// Procedury obsługi komunikatów CChildFrame
