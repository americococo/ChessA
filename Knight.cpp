#include "Knight.h"

void Knight::setup()
{
	{
		sPosition ps;
		ps.x = 1;
		ps.y = 2;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -1;
		ps.y = 2;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -2;
		ps.y = 1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -2;
		ps.y = -1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 2;
		ps.y = 1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 2;
		ps.y = -1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -1;
		ps.y = -2;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 1;
		ps.y = -2;
		relative_move.push_back(ps);
	}
	_piescesCode = 'K';

	return;
}