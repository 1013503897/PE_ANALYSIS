// ResourceInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "PEInfo.h"
#include "ResourceInfoDlg.h"
#include "afxdialogex.h"
#include "PEInfoDlg.h"

// ResourceInfoDlg 对话框

IMPLEMENT_DYNAMIC(ResourceInfoDlg, CDialogEx)

ResourceInfoDlg::ResourceInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

ResourceInfoDlg::~ResourceInfoDlg()
{
}

void ResourceInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(ResourceInfoDlg, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &ResourceInfoDlg::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// ResourceInfoDlg 消息处理程序


void ResourceInfoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CDialogEx::OnSize(nType, cx, cy);
	if (m_TreeCtrl)
	{
		CRect rect;
		GetClientRect(rect); 
		rect.bottom /= 2;
		rect.bottom -= 2;
		m_TreeCtrl.MoveWindow(rect);
	}
	if (m_ListCtrl)
	{
		CRect rect;
		GetClientRect(rect); 
		rect.top = rect.bottom / 2 + 2;
		m_ListCtrl.MoveWindow(rect);
	}
}


void ResourceInfoDlg::OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	CPEInfoDlg* Parent = (CPEInfoDlg*)GetParent();
	if (m_TreeCtrl.GetCount() > 1)
	{
		Parent->PrintResourceItem(pNMHDR, pResult);
	}
	*pResult = 0;
}


BOOL ResourceInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_ListCtrl.InsertColumn(0, _T("成员"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn(1, _T("偏移量"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn(2, _T("大小"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn(3, _T("值"), LVCFMT_LEFT, 100);
	return TRUE;  
				  
}
