#pragma once

class Snake
{
public:
	Snake();
private:
	CList<CPoint> snake_body;
	CPoint snake_direction;
public:
	void DrawSnake();
	CList<CPoint>* GetBody();
	bool Snake::IsInBody(CPoint point);
	bool MoveSnake(CPoint bean);
	void DirectionChange(CPoint direction);
};

