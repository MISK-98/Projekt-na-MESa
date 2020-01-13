
// MFCApplication1.cpp: definiuje zachowania klasy dla aplikacji.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCApplication1.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1App

BEGIN_MESSAGE_MAP(CMFCApplication1App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMFCApplication1App::OnAppAbout)
	// Standardowe polecenia dokumentu oparte na pliku
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standardowe polecenie konfiguracji wydruku
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// Konstrukcja klasy CMFCApplication1App

CMFCApplication1App::CMFCApplication1App() noexcept
{
	m_bHiColorIcons = TRUE;

	// obsługa menedżera ponownego uruchamiania
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Jeśli aplikacja została skompilowana z obsługą środowiska uruchomieniowego języka wspólnego (/clr):
	//     1) To dodatkowe ustawienie jest wymagane do poprawnego działania obsługi Menedżera ponownego uruchamiania.
	//     2) W projekcie musisz dodać odwołanie do elementu System.Windows.Forms, aby skompilować.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: Zastąp ciąg identyfikatora aplikacji poniżej za pomocą unikatowego ciągu identyfikatora; zalecane
	// format ciągu to CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCApplication1.AppID.NoVersion"));

	// TODO: W tym miejscu dodaj kod konstruktora,
	// Umieść wszystkie znaczące inicjacje w InitInstance
}

// Jedyny obiekt CMFCApplication1App

CMFCApplication1App theApp;


// Inicjowanie klasy CMFCApplication1App

BOOL CMFCApplication1App::InitInstance()
{
	// Funkcja InitCommonControlsEx() jest wymagana w systemie Windows XP, jeśli aplikacja
	// manifest określa użycie pliku ComCtl32.dll w wersji 6 lub nowszej, który ma zostać użyty
	// style wizualne. W przeciwnym razie utworzenie jakiegokolwiek okna nie powiedzie się.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Ustaw ten element tak, aby uwzględniał wszystkie typowe klasy kontrolek, których chcesz użyć
	// w aplikacji.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Zainicjuj biblioteki OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// Funkcja AfxInitRichEdit2() musi używać kontrolki RichEdit
	// AfxInitRichEdit2();

	// Inicjowanie standardowe
	// Jeśli nie używasz tych funkcji i chcesz zmniejszyć rozmiar
	// końcowego pliku wykonywalnego, usuń poniżej
	// określone procedury inicjowania, które nie są potrzebne
	// Zmień klucz rejestru, w którym są przechowywane ustawienia
	// TODO: zmodyfikuj ten ciąg, aby był poprawny
	// takie jak nazwa firmy lub organizacji
	SetRegistryKey(_T("Aplikacje lokalne wygenerowane przez kreatora aplikacji"));
	LoadStdProfileSettings(4);  // Ładuj opcje ze standardowego pliku INI (włącznie z listą ostatnio używanych)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Rejestruj szablony dokumentu aplikacji. Szablony dokumentu
	//  służą jako połączenie między dokumentami, oknami ramek i widokami
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_MFCApplication1TYPE,
		RUNTIME_CLASS(CMFCApplication1Doc),
		RUNTIME_CLASS(CChildFrame), // niestandardowa podrzędna ramka MDI
		RUNTIME_CLASS(CMFCApplication1View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// utwórz główne okno ramek MDI
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// Analizuj wiersz polecenia pod kątem standardowych poleceń powłoki, DDE i otwarcia pliku
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Polecenia wysyłania określone w wierszu polecenia. Zwraca wartość FALSE, jeśli
	// aplikacja została uruchomiona z parametrem /RegServer, /Register, /Unregserver lub /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// Zainicjowano okno główne, więc wyświetl je i zaktualizuj
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CMFCApplication1App::ExitInstance()
{
	//TODO: Obsłuż kolejne zasoby, które mogły zostać dodane
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// procedury obsługi komunikatów klasy CMFCApplication1App


// Okno dialogowe CAboutDlg używane na potrzeby informacji o aplikacji

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // obsługa DDX/DDV

// Implementacja
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Polecenie aplikacji uruchamiające okno dialogowe
void CMFCApplication1App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Metody ładowania/zapisu dostosowania klasy CMFCApplication1App

void CMFCApplication1App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CMFCApplication1App::LoadCustomState()
{
}

void CMFCApplication1App::SaveCustomState()
{
}

// procedury obsługi komunikatów klasy CMFCApplication1App



