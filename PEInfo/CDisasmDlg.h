#pragma once

// CDisasmDlg 对话框

class CDisasmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDisasmDlg)

public:
	CDisasmDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDisasmDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	CString m_edit_size;
	CString m_edit_offset;
	BOOL m_check;
	CComboBox m_combobox;
	CString m_edit_base;
	void InitEditAddress(int OEP, int OEP_VA);
};
