#pragma once


// CHexEditorDlg 对话框
#include "HexEdit.h"
class CHexEditorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHexEditorDlg)

public:
	CHexEditorDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHexEditorDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CHexEdit m_HexEditor;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CEdit m_edit1;
};
