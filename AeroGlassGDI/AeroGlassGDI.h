// AeroGlassGDI.h : AeroGlassGDI DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAeroGlassGDIApp
// �йش���ʵ�ֵ���Ϣ������� AeroGlassGDI.cpp
//

class CAeroGlassGDIApp : public CWinApp {
public:
    CAeroGlassGDIApp();

    // ��д
public:
    virtual BOOL InitInstance();

    DECLARE_MESSAGE_MAP()
};
