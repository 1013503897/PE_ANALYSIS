#include "pch.h"
#include "PEInfo.h"
#include "CDisasmDlg.h"
#include "afxdialogex.h"
#include "PEInfoDlg.h"

IMPLEMENT_DYNAMIC(CDisasmDlg, CDialogEx)

CDisasmDlg::CDisasmDlg(CWnd* pParent)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_edit_size(_T(""))
	, m_edit_offset(_T(""))
	, m_check(FALSE)
	, m_edit_base(_T(""))
{

}

CDisasmDlg::~CDisasmDlg()
{
}

void CDisasmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
	DDX_Text(pDX, IDC_EDIT2, m_edit_size);
	DDX_Text(pDX, IDC_EDIT1, m_edit_offset);
	DDX_Check(pDX, IDC_CHECK1, m_check);
	DDX_Control(pDX, IDC_COMBO1, m_combobox);
	DDX_Text(pDX, IDC_EDIT4, m_edit_base);
}

BEGIN_MESSAGE_MAP(CDisasmDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDisasmDlg::OnBnClickedButton1)
	ON_WM_SIZE()
END_MESSAGE_MAP()


void CDisasmDlg::OnBnClickedButton1()
{
	CPEInfoDlg* Parent = (CPEInfoDlg*)GetParent();
	UpdateData(true);
	Parent->StartDisasm();
}

void CDisasmDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	
	if (m_ListCtrl)
	{
		CRect rectDlg;
		GetClientRect(rectDlg);
		rectDlg.DeflateRect(0, 210, 0, 0);
		GetDlgItem(IDC_STATIC3)->MoveWindow(rectDlg);
		rectDlg.DeflateRect(1, 24, 1, 1);
		m_ListCtrl.MoveWindow(rectDlg);
	}
}

BOOL CDisasmDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_check = true;
	m_edit_size = _T("1000");	
	m_combobox.AddString(_T("x86"));
	m_combobox.AddString(_T("x64"));
	m_combobox.SetCurSel(1);
	m_ListCtrl.InsertColumn(0, _T("地址"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn(1, _T("机器码"), LVCFMT_LEFT, 200);
	m_ListCtrl.InsertColumn(2, _T("指令"), LVCFMT_LEFT, 250);

	UpdateData(false);
	return TRUE;  	  
}


void CDisasmDlg::InitEditAddress(int OEP, int OEP_VA)
{
	m_edit_base.Format(_T("%08X"), OEP_VA);
	m_edit_offset.Format(_T("%X"), OEP);
	UpdateData(false);
}