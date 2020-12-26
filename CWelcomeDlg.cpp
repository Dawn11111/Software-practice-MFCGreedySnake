// CWelcomeDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCGreedySnake.h"
#include "CWelcomeDlg.h"
#include "afxdialogex.h"
#include "MFCGreedySnakeDlg.h"


// CWelcomeDlg 对话框

IMPLEMENT_DYNAMIC(CWelcomeDlg, CDialogEx)

CWelcomeDlg::CWelcomeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WELCOME, pParent)
{

}

CWelcomeDlg::~CWelcomeDlg()
{
}

void CWelcomeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWelcomeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CWelcomeDlg::OnBnClickedWelcome)
END_MESSAGE_MAP()


// CWelcomeDlg 消息处理程序


void CWelcomeDlg::OnBnClickedWelcome()
{
	CDialogEx::OnOK(); //关闭主界面
	CMFCGreedySnakeDlg dlg;
	dlg.DoModal();
}
