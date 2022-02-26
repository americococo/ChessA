#include "Board.h"
#include "Pieces.h"
#include "piecesH.h"
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

bool Board::piecesMove(sPosition chPos, sPosition relMove)
{
	sPosition realtionMove;
	realtionMove.y = relMove.y - chPos.y;
	realtionMove.x = relMove.x - chPos.x;

	if (true == _mapData[chPos.y][chPos.x]->isMoving(realtionMove))
	{
		_mapData[relMove.y][relMove.x] =
			_mapData[chPos.y][chPos.x];

		Pieces* pic;
		if (canPromotion(relMove))
		{
			pic = ((Pawn*)_mapData[relMove.y][relMove.x])->Promotion();
			delete _mapData[relMove.y][relMove.x];
			_mapData[relMove.y][relMove.x] = pic;
		}
		_mapData[chPos.y][chPos.x] = nullptr;
		return true;
	}
	return false;
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
	char pawncode = 'p';
	if (nullptr != _mapData[piePos.y][piePos.x])
		if(pawncode = _mapData[piePos.y][piePos.x]->getPiecesCode())
		if (piePos.y == 0 || piePos.y == 7)
			return true;
		
	return false;
}

Pieces* Board::searchPieces(char  picName,bool picColor) 
{
	Pieces* pic=nullptr;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (nullptr != _mapData[i][j])
				if (picName == _mapData[i][j]->getPiecesCode()
					&&picColor == _mapData[i][j]->getColor())
				{
					pic = _mapData[i][j];
				}
		}
	}
	return pic;
}