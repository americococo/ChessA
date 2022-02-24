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

