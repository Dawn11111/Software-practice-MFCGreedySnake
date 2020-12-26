#include "pch.h"
#include "Snake.h"

Snake::Snake()
{
	//��ʼ����Ϊ3���������м�
	snake_body.AddTail(CPoint(30, 29));
	snake_body.AddTail(CPoint(30, 30));
	snake_body.AddTail(CPoint(30, 31));
	//��ʼ����������
	snake_direction.SetPoint(0, -1);
}

void Snake::DrawSnake()
{
	
}


CList<CPoint>* Snake::GetBody()
{
	return &snake_body;
}


//�����������Ķ���������λ����
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
	CPoint newHead = snake_body.GetHead() + snake_direction;//�µ���ͷλ��
	if (IsInBody(newHead))//ײ���Լ�
		return false;
	if (newHead != food) //û�Ե�����
	{
		snake_body.RemoveTail();//ɾ����β
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
	snake_body.AddHead(newHead);//�µ���ͷ����ǰ��
	
		return true;
	
}



void Snake::DirectionChange(CPoint direction)
{
	snake_direction = direction;
}



