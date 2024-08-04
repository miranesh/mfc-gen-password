
// genpasswordDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "genpassword.h"
#include "genpasswordDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CgenpasswordDlg



CgenpasswordDlg::CgenpasswordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GENPASSWORD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgenpasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PASSWORD, m_password);
	DDX_Control(pDX, IDC_LENGHT, m_lenght);
	DDX_Control(pDX, IDC_LETTERS_CHECK, m_letter);
	DDX_Control(pDX, IDC_NUMBER_CHECK, m_number);
	DDX_Control(pDX, IDC_SYMBOLS_CHECK, m_symbols);
	DDX_Control(pDX, IDC_BUTTON, m_test);
}

BEGIN_MESSAGE_MAP(CgenpasswordDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON, &CgenpasswordDlg::OnBnClickedButton)
END_MESSAGE_MAP()


// Обработчики сообщений CgenpasswordDlg

BOOL CgenpasswordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	// 
	//Как скрыть кнопку в MFC c использованием объекта CButton?
	//m_test.ShowWindow(SW_HIDE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CgenpasswordDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CgenpasswordDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CgenpasswordDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CgenpasswordDlg::OnBnClickedButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	CString password;

	int lenght = GetDlgItemInt(IDC_LENGHT);
	if (lenght <= 0) {
		AfxMessageBox(_T("Введите длину пароля!")); //10
		return;
	}

	CString characters;

	if (m_letter.GetCheck() == BST_CHECKED) {
		characters += _T("ABCDEFGHIJKLMOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	}
	if (m_number.GetCheck() == BST_CHECKED) { //флажок только тут
		characters = characters + _T("0123456789");
	}
	if (m_symbols.GetCheck() == BST_CHECKED) {
		characters += _T("!@#$%^&*()_+{}[]<>?");
	}

	if (characters.IsEmpty()) {
		AfxMessageBox(_T("Выберите типы символов для пароля!"));
		return;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < lenght; i++) { 
		int index;
		index = rand() % characters.GetLength(); 
		password += characters[index]; 
	}

	m_password.SetWindowText(password);
}
