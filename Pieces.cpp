#include "Pieces.h"


#include <stdio.h>

void Pieces::print()
{

	std::vector<sPosition>::iterator itr = relative_move.begin();

	for (; itr!=relative_move.end(); itr++)
	{
		printf("x축 이동 방향 %d\n", (*itr).x);
		printf("y축 이동 방향 %d\n", (*itr).y);
		printf("\n\n");
		
	}

	relative_move;

	return;
}
bool Pieces::isMoving(sPosition postion)
{
	std::vector<sPosition>::iterator itr = relative_move.begin();

	for (; itr != relative_move.end(); itr++)
	{
		if (true == isEqualPosition((*itr), postion))
			return true;
	}

	return false;
}