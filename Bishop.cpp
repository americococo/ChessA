#include "Bishop.h"

void Bishop::setup()
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

	return;
}