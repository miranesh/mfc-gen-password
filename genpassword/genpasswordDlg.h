
// genpasswordDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CgenpasswordDlg
class CgenpasswordDlg : public CDialogEx
{
// Создание
public:
	CgenpasswordDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GENPASSWORD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_password;
	CEdit m_lenght;
	CButton m_letter;
	CButton m_number;
	CButton m_symbols;
	afx_msg void OnBnClickedButton();
	CButton m_test;
};
