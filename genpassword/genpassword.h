﻿
// genpassword.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CgenpasswordApp:
// Сведения о реализации этого класса: genpassword.cpp
//

class CgenpasswordApp : public CWinApp
{
public:
	CgenpasswordApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CgenpasswordApp theApp;
