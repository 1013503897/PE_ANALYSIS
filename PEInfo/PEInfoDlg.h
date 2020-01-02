#pragma once
#include "TableInfoDlg.h"
#include "ResourceInfoDlg.h"
#include "CDisasmDlg.h"
#include "CHexEditorDlg.h"
#pragma comment(lib,"Version.lib")

typedef struct ExportDirectoryInfo {
	TCHAR FunctionName[MAX_PATH];
	WORD FunctionOrdinals;
	DWORD FunctionAddress;
	DWORD FunctionNameRVA;
}_ExportDirectoryInfo, * _pExportDirectoryInfo;

class CPEInfoDlg : public CDialogEx
{
public:
	CPEInfoDlg(CWnd* pParent = nullptr);	

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PEINFO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	

protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	TCHAR FileFullPath[MAX_PATH] = { 0 };
	TCHAR FileName[MAX_PATH] = {0};
	char* FileAddress = NULL;
	TableInfoDlg* m_TableInfoDlg = NULL;
	CImageList m_ImageList;
	ResourceInfoDlg* m_ResourceInfoDlg = NULL;
	CDisasmDlg* m_CDisasmDlg = NULL;
	CHexEditorDlg* m_HexEditorDlg = NULL; 
	DWORD FileSize;
public:
	afx_msg void OnDropFiles(HDROP hDropInfo);
	void ClearListCtrl();
	void PrintFileInfo();
	void PrintDosHeader();
	void PrintNtHeader();
	CString GetVariableSize(int size);
	CString Int2CString(int data, int length);
	CString Int2CString(int data);
	CTreeCtrl m_TreeCtrl;
	CListCtrl m_ListCtrl;
	afx_msg void OnTvnSelchangedTree3(NMHDR* pNMHDR, LRESULT* pResult);
	void PrintFileHeader();
	void PrintOptionalHeader();
	void PrintSectionHeader();
	void PrintDataDirectory();
	DWORD FOA_TO_RVA(DWORD FOA);
	DWORD RVA_TO_FOA(DWORD RVA); 
	void GetSectionName(DWORD RVA, TCHAR* Name);
	void GetFileInfo();
	BOOL HaveExportTable();
	BOOL HaveImportTable();
	BOOL HaveRelocationTable();
	BOOL HaveResourceTable();
	void GetFileFullPath();
	void PrintImportTable();
	void PrintResourceTable();
	void PrintExportTable();
	void PrintRelocationTable();
	afx_msg void PrintHexEditor();
	void PrintAddressConvert();
	void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMove(int x, int y);
	void MyExpandTree(HTREEITEM hTreeItem);
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	void PrintDisasmDlg();
	void StartDisasm();
	void HideConvertGroup();
	void PrintResourceItem(NMHDR* pNMHDR, LRESULT* pResult);
	CEdit m_edit_VA;
	CEdit m_edit_RVA;
	CEdit m_edit_FOA;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	bool isconverting = false;
};


void md4_encrypt(const void* data, size_t len, CString& ret);
void md5_encrypt(const void* data, size_t len, CString& ret);
void sha1_encrypt(const void* data, size_t len, CString& ret);