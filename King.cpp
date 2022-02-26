#include "King.h"

void King::setup()
{
	{
		sPosition ps;
		ps.x = 1;
		ps.y = 1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -1;
		ps.y = 1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 1;
		ps.y = -1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -1;
		ps.y = -1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 1;
		ps.y = 0;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -1;
		ps.y = 0;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 0;
		ps.y = 1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 0;
		ps.y = -1;
		relative_move.push_back(ps);
	}
	_piescesCode = 'K';
	return;
}

void King::moveAction()
{
	_oneMove = true;
	return;
}

bool King::isMoving(sPosition postion)
{
	std::vector<sPosition>::iterator itr = relative_move.begin();

	for (; itr != relative_move.end(); itr++)
	{
		if (true == isEqualPosition((*itr), postion))
		{
			moveAction();
			return true;
		}
	}

	return false;
}
