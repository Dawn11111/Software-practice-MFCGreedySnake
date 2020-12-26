
// MFCGreedySnakeDlg.h: 头文件
//

#pragma once
#include "Snake.h"


// CMFCGreedySnakeDlg 对话框
class CMFCGreedySnakeDlg : public CDialogEx
{
// 构造
public:
	CMFCGreedySnakeDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCGREEDYSNAKE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	CPoint m_ptFood;
	Snake m_snake;
public:
	void setBean();
	afx_msg void OnBnClickedStart();
	void DrawSnake();
	void StartMove();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedUp();
	afx_msg void OnBnClickedDown();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRight();
private:
	int m_score;
public:
	void SnakeMove();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedLevel();
	CEdit m_level;
	CEdit mScore;
	int eat_bean=0;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
