#include "Rook.h"

void Rook::setup()
{
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
	_oneMove = false;
	_piescesCode = 'R';
	return;
}
void Rook::moveAction()
{
	_oneMove = true;
	return;
}