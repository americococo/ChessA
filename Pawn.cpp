#include "Pawn.h"

#include "piecesH.h"
#include <stdio.h>

void Pawn::setup()
{
	{
		sPosition ps;
		ps.x = 0;
		ps.y = 2;
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

	if (_color != true)
	{
		std::vector<sPosition>::iterator itr = relative_move.begin();

		for (; itr != relative_move.end(); itr++)
		{
			(*itr).y = (*itr).y * -1;
		}
	}
	_piescesCode = 'P';
	return;
}

Pieces* Pawn::Promotion()
{
	char change_piecesShape;

	printf("프로모션 찬스!!!!\n");
	printf("B. bishop \t R. rook \t N. kNight Q. queen \n");

	{
		while (getchar() != '\n');
	}

	scanf_s("%c", &change_piecesShape, 1);

	Pieces* pic;

	switch (change_piecesShape)
	{
	case 'B':
		pic = new Bishop(_color);
		break;
	case 'R':
		pic = new Rook(_color);
		break;
	case 'N':
		pic = new Knight(_color);
		break;
	case 'Q':
	default:
		pic = new Queen(_color);
		break;
	}
	pic->print();
	return pic;
}
void Pawn::moveAction()
{

	if (_oneMove == false)
	{
		printf("훗 최초의 이동이라구\n");
		relative_move.erase(relative_move.begin());

	}
	_oneMove = true;

	print();

	return;
}
