// AeroGlassGDI.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "AeroGlassGDI.h"

#include "../common/aerosubc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CAeroGlassGDIApp, CWinApp)
END_MESSAGE_MAP()


// CAeroGlassGDIApp 构造

CAeroGlassGDIApp::CAeroGlassGDIApp() {
    // TODO: 在此处添加构造代码，
    // 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CAeroGlassGDIApp 对象

CAeroGlassGDIApp theApp;


// CAeroGlassGDIApp 初始化

BOOL GetNtVersionNumbers(DWORD &dwMajorVer, DWORD & dwMinorVer, DWORD & dwBuildNumber) {

	BOOL bRet = FALSE;

	HMODULE hModNtdll = NULL;

	if (hModNtdll = ::LoadLibraryW(L"ntdll.dll")) {
		typedef void (WINAPI *pfRTLGETNTVERSIONNUMBERS)(DWORD*, DWORD*, DWORD*);
		pfRTLGETNTVERSIONNUMBERS pfRtlGetNtVersionNumbers;
		pfRtlGetNtVersionNumbers = (pfRTLGETNTVERSIONNUMBERS)::GetProcAddress(hModNtdll, "RtlGetNtVersionNumbers");
		if (pfRtlGetNtVersionNumbers) {
			pfRtlGetNtVersionNumbers(&dwMajorVer, &dwMinorVer, &dwBuildNumber);
			dwBuildNumber &= 0x0ffff;
			bRet = TRUE;
		}
		::FreeLibrary(hModNtdll);
		hModNtdll = NULL;
	}
	return bRet;
}

BOOL isValidSystem() {
	DWORD a, b, c;
	if (GetNtVersionNumbers(a, b, c)) {
		if (a >= 6 && b >= 0) return TRUE;
	}
	return FALSE;
}

BOOL CAeroGlassGDIApp::InitInstance() {
    CWinApp::InitInstance();
    return TRUE;
}
