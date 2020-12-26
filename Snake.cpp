#include "pch.h"
#include "Snake.h"

Snake::Snake()
{
	//初始长度为3，放在正中间
	snake_body.AddTail(CPoint(30, 29));
	snake_body.AddTail(CPoint(30, 30));
	snake_body.AddTail(CPoint(30, 31));
	//初始化方向向上
	snake_direction.SetPoint(0, -1);
}

void Snake::DrawSnake()
{
	
}


CList<CPoint>* Snake::GetBody()
{
	return &snake_body;
}


//如果随机产生的豆子在蛇身位置上
bool Snake::IsInBody(CPoint point) {
	POSITION p = snake_body.GetHeadPosition();
	while (p)
	{
		if (point == snake_body.GetNext(p))
			return true;
	}
	return false;
}



bool Snake::MoveSnake(CPoint food)
{
	CPoint newHead = snake_body.GetHead() + snake_direction;//新的蛇头位置
	if (IsInBody(newHead))//撞到自己
		return false;
	if (newHead != food) //没吃到豆子
	{
		snake_body.RemoveTail();//删掉蛇尾
	}
	if (newHead.x < 0) {
		newHead.x = newHead.x + 60;
	}
	else if (newHead.x > 60) {
		newHead.x = newHead.x - 60;
	}
	else if (newHead.y < 0) {
		newHead.y = newHead.y + 60;
	}
	else if (newHead.y > 60) {
		newHead.y = newHead.y - 60;
	}
	snake_body.AddHead(newHead);//新的蛇头在最前面
	
		return true;
	
}



void Snake::DirectionChange(CPoint direction)
{
	snake_direction = direction;
}



