
// MFCGreedySnakeDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCGreedySnake.h"
#include "MFCGreedySnakeDlg.h"
#include "afxdialogex.h"
#include "CWelcomeDlg.h"
#include "Snake.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define LENGTH 10
#define SIZE_H 60
#define SIZE_V 60

//新增代码
//IMPLEMENT_DYNAMIC(MFCGreedySnakeDlg, CDialogEx)


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCGreedySnakeDlg 对话框



CMFCGreedySnakeDlg::CMFCGreedySnakeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCGREEDYSNAKE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCGreedySnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_level);
	DDX_Control(pDX, IDC_EDIT2, mScore);
}

BEGIN_MESSAGE_MAP(CMFCGreedySnakeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCGreedySnakeDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCGreedySnakeDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCGreedySnakeDlg::OnBnClickedUp)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCGreedySnakeDlg::OnBnClickedDown)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCGreedySnakeDlg::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCGreedySnakeDlg::OnBnClickedRight)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCGreedySnakeDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCGreedySnakeDlg::OnBnClickedLevel)
END_MESSAGE_MAP()


// CMFCGreedySnakeDlg 消息处理程序

BOOL CMFCGreedySnakeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCGreedySnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCGreedySnakeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CClientDC dc(this);
		dc.Rectangle(0, 0, LENGTH * SIZE_H, LENGTH * SIZE_V);
		//DrawSnake();
		//setBean();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCGreedySnakeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMFCGreedySnakeDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}




void CMFCGreedySnakeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SnakeMove();
	CDialogEx::OnTimer(nIDEvent);
}




//开始游戏按键
void CMFCGreedySnakeDlg::OnBnClickedStart()
{
	DrawSnake();
	setBean();
	StartMove();
	
}


//暂停游戏
void CMFCGreedySnakeDlg::OnBnClickedStop()
{
	KillTimer(1);
}


void CMFCGreedySnakeDlg::OnBnClickedUp()
{
	// 上
	m_snake.DirectionChange(CPoint(0, -1));
}


void CMFCGreedySnakeDlg::OnBnClickedDown()
{
	// 下
	m_snake.DirectionChange(CPoint(0, 1));
}


void CMFCGreedySnakeDlg::OnBnClickedLeft()
{
	// 左
	m_snake.DirectionChange(CPoint(-1, 0));
}


void CMFCGreedySnakeDlg::OnBnClickedRight()
{
	// 右
	m_snake.DirectionChange(CPoint(1, 0));
}


//退出游戏
void CMFCGreedySnakeDlg::OnBnClickedExit()
{
	KillTimer(1);
	MessageBox(_T("游戏结束！"));
	EndDialog(0);
}


BOOL CMFCGreedySnakeDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_UP:
			m_snake.DirectionChange(CPoint(0, -1));
			break;
		case VK_DOWN:
			m_snake.DirectionChange(CPoint(0, 1));
			break;
		case VK_LEFT:
			m_snake.DirectionChange(CPoint(-1, 0));
			break;
		case VK_RIGHT:
			m_snake.DirectionChange(CPoint(1, 0));
			break;
		default:
			break;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}












//蛇的形状与蛇身的构造
void CMFCGreedySnakeDlg::DrawSnake()
{
	CClientDC dc(this);
	CBrush red(RGB(255, 0, 0));
	dc.SelectObject(red);
	CList<CPoint>* pBody = m_snake.GetBody();
	//遍历整个蛇身，画出整条蛇
	POSITION p = pBody->GetHeadPosition();
	while (p)
	{
		CPoint point = pBody->GetNext(p);
		dc.Rectangle(point.x * LENGTH, point.y * LENGTH,
			(point.x + 1) * LENGTH, (point.y + 1) * LENGTH);
	}
}


//设置豆子的随机位置
void CMFCGreedySnakeDlg::setBean()
{
	srand(time(NULL));					//初始化rand函数
	m_ptFood.x = rand() % 58 + 1;		//随机产生x、y坐标
	m_ptFood.y = rand() % 58 + 1;
	//豆子随机生成的位置在除蛇以外的区域
	while (m_snake.IsInBody(m_ptFood)) {
		m_ptFood.x = rand() % 80 + 1;
		m_ptFood.y = rand() % 80 + 1;
	}
	//绘出豆子
	CClientDC dc(this);
	int n = rand() % 255 + 1;
	//CBrush blue(RGB(n,255-n, n));
	CBrush blue(RGB((eat_bean*70)%255, 255- (eat_bean * 70) % 255, (eat_bean *100) % 255));
	dc.SelectObject(blue);
	dc.Rectangle(m_ptFood.x * LENGTH, m_ptFood.y * LENGTH,
		(m_ptFood.x + 1) * LENGTH, (m_ptFood.y + 1) * LENGTH);
}



//开始移动小蛇
void CMFCGreedySnakeDlg::StartMove()
{
	setBean();
	OnBnClickedLevel();
}


//小蛇的移动(链表
void CMFCGreedySnakeDlg::SnakeMove()
{
	CClientDC dc(this);
	CPoint tail = m_snake.GetBody()->GetTail();//获取之前的蛇尾
	
	if (m_snake.MoveSnake(m_ptFood))//移动成功
	{
		CPoint head = m_snake.GetBody()->GetHead();//获取新的蛇头
		CBrush red(RGB(255, 0, 0));
		CBrush* old = dc.SelectObject(&red);
		dc.Rectangle(head.x * LENGTH, head.y * LENGTH,
			(head.x + 1) * LENGTH, (head.y + 1) * LENGTH);
		dc.SelectObject(old);
		CString b;
		if (head == m_ptFood)//如果吃到豆子，则产生新豆子
		{
			++eat_bean;
			setBean();
			b.Format(_T("% d"), eat_bean);
			mScore.SetWindowText(b);
		}
		else//否则删去蛇尾
		{
			CPen white(PS_SOLID, 1, RGB(255, 255, 255));
			dc.SelectObject(white);
			dc.Rectangle(tail.x * LENGTH, tail.y * LENGTH,
				(tail.x + 1) * LENGTH, (tail.y + 1) * LENGTH);
		}
		

	}
	else
	{
		KillTimer(1);
		MessageBox(_T("游戏结束！"));
	}
}


//自行设置小蛇的速度作为游戏等级的不同
void CMFCGreedySnakeDlg::OnBnClickedLevel()
{
	CString str;
	m_level.GetWindowText(str);
	int num;
	num = _ttoi(str);
	switch (num)
	{
	case 1:
		SetTimer(1, 1000, NULL);
		break;
	case 2:
		SetTimer(1, 900, NULL);
		break;
	case 3:
		SetTimer(1, 800, NULL);
		break;
	case 4:
		SetTimer(1, 700, NULL);
		break;
	case 5:
		SetTimer(1, 600, NULL);
		break;
	case 6:
		SetTimer(1, 500, NULL);
		break;
	case 7:
		SetTimer(1, 400, NULL);
		break;
	case 8:
		SetTimer(1, 300, NULL);
		break;
	case 9:
		SetTimer(1, 200, NULL);
		break;
	default:
		SetTimer(1, 1000, NULL);
		m_level.SetWindowText(_T("默认1"));
		break;
	}
}

