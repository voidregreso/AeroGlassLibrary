// AeroGlassGDI.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "AeroGlassGDI.h"

#include "../common/aerosubc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CAeroGlassGDIApp, CWinApp)
END_MESSAGE_MAP()


// CAeroGlassGDIApp ����

CAeroGlassGDIApp::CAeroGlassGDIApp() {
    // TODO: �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAeroGlassGDIApp ����

CAeroGlassGDIApp theApp;


// CAeroGlassGDIApp ��ʼ��

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
