#include "Board.h"
#include "Pieces.h"
#include "piecesH.h"
#include <stdio.h>
#include <string.h>

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
bool Board::isThatAEmpty(int y, int x)
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
		//상대 직전 기보 데이터 가져와서 폰 2칸 움직였는지 체크 & 내 폰 양옆에 폰이 있는지 체크
		//앙파상

		int diffY = atoi(&getLastgiboData[2][0]) - atoi(&getLastgiboData[1][0]);

		if (getLastgiboData[0][0] == 'P' && diffY == 20 && _mapData[chPos.y][chPos.x]->getPiecesCode() == 'P')
		{
			if (nullptr != _mapData[chPos.y][relMove.x] && _mapData[chPos.y][relMove.x]->getPiecesCode())
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

				//앙파상으로 따먹은 폰
				delete _mapData[chPos.y][relMove.x];

				return true;

			}
		}

		//일반 이동
		if (nullptr == _mapData[relMove.y][relMove.x])
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

		//말따먹기 용
		if (false == (_mapData[relMove.y][relMove.x]->getColor() == _mapData[chPos.y][chPos.x]->getColor()))
		{

			delete _mapData[relMove.y][relMove.x];

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

	}
	return false;
}

void Board::printBoard()
{
	printf("|=====||=====||=====||=====||=====||=====||=====||=====|\n");

	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (nullptr == _mapData[i][j])
				printf("|     |");
			else
				printf("|  %c  |", _mapData[i][j]->getPiecesCode());
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
		if (pawncode = _mapData[piePos.y][piePos.x]->getPiecesCode())
			if (piePos.y == 0 || piePos.y == 7)
				return true;

	return false;
}

Pieces* Board::searchPieces(char  picName, bool picColor)
{
	Pieces* pic = nullptr;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (nullptr != _mapData[i][j])
				if (picName == _mapData[i][j]->getPiecesCode()
					&& picColor == _mapData[i][j]->getColor())
				{
					pic = _mapData[i][j];
				}
		}
	}
	return pic;
}


void Board::insertLastgiboData(char giboData[])
{
	char* passing = nullptr;
	char* token[3] = { NULL,NULL,NULL };
	token[0] = strtok_s(giboData, " ", &passing);
	token[1] = strtok_s(NULL, " ", &passing);
	token[2] = strtok_s(NULL, " ", &passing);

	if (token[0] != NULL)
	{
		strcpy_s(getLastgiboData[0], token[0]);
		strcpy_s(getLastgiboData[1], token[1]);
		strcpy_s(getLastgiboData[2], token[2]);
	}
}