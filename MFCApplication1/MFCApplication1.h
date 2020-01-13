
// MFCApplication1.h: główny plik nagłówkowy aplikacji MFCApplication1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "dołącz nagłówek „pch.h” przed dołączeniem tego pliku na potrzeby optymalizacji PCH"
#endif

#include "resource.h"       // główne symbole


// CMFCApplication1App:
// Aby uzyskać implementację klasy, zobacz MFCApplication1.cpp
//

class CMFCApplication1App : public CWinAppEx
{
public:
	CMFCApplication1App() noexcept;


// Przesłania
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementacja
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication1App theApp;
