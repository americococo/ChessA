#include "Board.h"
#include "Pieces.h"
#include <stdio.h>
Board::Board()
{
	_mapData.clear();
	for (int i = 0; i < 8; i++)
	{
		std::vector<Pieces*> pie;
		for (int j = 0; j < 8; j++)
		{
			pie.push_back(nullptr);
		}
		_mapData.push_back(pie);
	}

}
bool Board::isThatAEmpty(int y,int x)
{
	if (nullptr != _mapData[y][x])
		return false;
	return true;
}
int Board::settingBoard(Pieces* pic, sPosition pos)
{
	_mapData[pos.y][pos.x] = pic;

	return 0;
}

void Board::piecesMove(sPosition chPos, sPosition relMove)
{
	if (true == _mapData[chPos.y][chPos.x]->isMoving(relMove))
	{
		_mapData[chPos.y + relMove.y][chPos.x + relMove.x] =
			_mapData[chPos.y][chPos.x];

		_mapData[chPos.y][chPos.x] = nullptr;
	}
}

void Board::printBoard()
{
	printf("|=====||=====||=====||=====||=====||=====||=====||=====|\n");

	for (int i = 7; i >= 0 ; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (nullptr == _mapData[i][j])
				printf("|     |");
			else
				printf("|  %c  |",_mapData[i][j]->getPiecesCode());
		}
		printf("\n");
		if (i >= 1)
			printf("|-----||-----||-----||-----||-----||-----||-----||-----|\n");
	}
	printf("|=====||=====||=====||=====||=====||=====||=====||=====|\n");
}

bool Board::canPromotion(sPosition piePos)
{
	if (nullptr == _mapData[piePos.y][piePos.x])
		if (piePos.y == 0 || piePos.y == 7)
			return true;
		
	return false;
}
