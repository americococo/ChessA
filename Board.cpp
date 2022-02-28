#include "Board.h"
#include "Pieces.h"
#include "piecesH.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>

Board::Board()
{
	_bigColorPieces.clear();
	_smallColorPieces.clear();

}

int Board::settingBoard(Pieces* pic, sPosition pos)
{
	pic->settingPosition(pos);
	_mapData[pos.y][pos.x] = pic->PiecesPrintCode();

	return 0;
}
void Board::move(Pieces * pic, sPosition sePos)
{

	_mapData[sePos.y][sePos.x] = _mapData[pic->getPos().y][pic->getPos().x];
	_mapData[pic->getPos().y][pic->getPos().x] = '\0';
}

bool Board::piecesMove(Pieces * pic, sPosition relMove)
{
	sPosition realtionMove;

	realtionMove.y = relMove.y - pic->getPos().y;
	realtionMove.x = relMove.x - pic->getPos().x;

	if (pic->getPos().y + relMove.y > 8 || pic->getPos().x + relMove.x > 8
		|| pic->getPos().x + relMove.x < -1 || pic->getPos().y + relMove.y < -1)
		return false;

	//캐슬링
	
	if (pic->getPiecesCode() == 'K' && relMove.y == 0 && (relMove.x == 2 || relMove.x == -2 ))
	{
		if (false == ((King*)pic)->amIDanger())
		{
			move(pic, addPosition(pic->getPos(), relMove);
			pic->moveAction();
			pic->settingPosition(addPosition(pic->getPos(), relMove));

			Pieces * rook;
			if (pic->getColor())
				for (auto itr = _bigColorPieces.begin(); itr != _bigColorPieces.end(); itr++)
				{
					if ((*itr)->getPiecesCode() == 'R')
					{
						if (relMove.x > 0 && (7 == (*itr)->getPos().x))
						{
							rook = (*itr)
						}
						else if (relMove.x < 0 && (0 == (*itr)->getPos().x))
						{
							rook = (*itr);
						}
						else
							return false;
					}
				}
			sPosition rookMove;
			rookMove = addPosition(pic->getPos(), relMove);

			rookMove.y = (relMove.y / 2) * -1;
			move(rook, addPosition(pic->getPos(), relMove));
			rook->moveAction();
			rook->settingPosition(addPosition(pic->getPos(), relMove));
		}
	}


	if (true == pic->isMoving(relMove))
	{
		//상대 직전 기보 데이터 가져와서 폰 2칸 움직였는지 체크 & 내 폰 양옆에 폰이 있는지 체크
		//앙파상

		int diffY = atoi(&getLastgiboData[1][0]);

		if (getLastgiboData[0][0] == 'P' && diffY == 20 && pic->getPiecesCode() == 'P')
		{
			std::vector<Pieces*> enemyV;
			if (pic->getColor())
				enemyV = _smallColorPieces;
			else
				enemyV = _bigColorPieces;

			auto itr = enemyV.begin();

			std::vector<Pieces *> delete_Pieceses;

			for (; itr!=enemyV.end(); itr++)
			{
				if (pic->getPos().y == (*itr)->getPos().y && ((*itr)->getPos().x == relMove.x + pic->getPos().x))
				{
					sPosition sePos;
					sePos.y = pic->getPos().y + relMove.y;
					sePos.x = pic->getPos().x + relMove.x;
					move(pic, sePos);
					pic->moveAction();
					pic->settingPosition(sePos);
					delete_Pieceses.push_back((*itr));

					if (pic->getPiecesCode()=='P' && canPromotion(pic))
					{
						Pieces* chosP;
						chosP = ((Pawn*)pic)->Promotion();
						chosP->settingPosition(pic->getPos());
						delete_Pieceses.push_back(pic);

						true;
					}
				}
			}
			
			for (int i = 0; i < delete_Pieceses.size(); i++)
			{
				delete delete_Pieceses[i];
			}
			
		}

		//일반 이동
		{
			sPosition sePos;
			sePos.y = pic->getPos().y + relMove.y;
			sePos.x = pic->getPos().x + relMove.x;

			std::vector<Pieces*>::iterator itr;

			if (pic->getColor())
				itr = _bigColorPieces.begin();
			else
				itr = _smallColorPieces.begin();


			

			for (;  itr!= (pic->getColor()?_bigColorPieces.end():_smallColorPieces.end()); itr++)
			{
				if (isEqualPosition((*itr)->getPos(), sePos))
					continue;


				move(pic, sePos);
				pic->moveAction();
				pic->settingPosition(sePos);


				if (pic->getPiecesCode() == 'P' && canPromotion(pic))
				{
					Pieces* chosP;
					chosP = ((Pawn*)pic)->Promotion();
					chosP->settingPosition(pic->getPos());
					delete pic;
					return true;
				}
				
				return true;
			}
		}

	}
	return false;
}

void Board::printBoard()
{

	system("cls");
	printf("|=====||=====||=====||=====||=====||=====||=====||=====|\n");

	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if ('\0' == _mapData[i][j])
				printf("|     |");
			else
				printf("|  %c  |", _mapData[i][j]);
		}
		printf("\n");
		if (i >= 1)
			printf("|-----||-----||-----||-----||-----||-----||-----||-----|\n");
	}
	printf("|=====||=====||=====||=====||=====||=====||=====||=====|\n");
}
bool Board::canPromotion(Pieces * pic)
{
	if (pic->getPos().y == 0 || pic->getPos().y == 7)
		return true;

	return false;
}

Pieces* Board::searchPieces(char picName, bool picColor, sPosition position)
{
	Pieces* pic=nullptr;

	std::vector<Pieces*>::iterator itr;

	itr = picColor ? _bigColorPieces.begin() : _smallColorPieces.begin();

	for (; itr != (picColor?_bigColorPieces.end():_smallColorPieces.end()) ; itr++)
	{
		if (isEqualPosition( (*itr)->getPos(), position))
		{
			pic = (*itr);
		}
	}


	return pic;
}

void Board::insertLastgiboData(char giboData[])
{
	char* passing = nullptr;
	char* token[4] = { NULL,NULL,NULL };
	token[0] = strtok_s(giboData, " ", &passing);
	token[1] = strtok_s(NULL, " ", &passing);
	token[2] = strtok_s(NULL, " ", &passing);
	token[3] = strtok_s(NULL, " ", &passing);
	if (token[0] != NULL)
	{
		strcpy_s(getLastgiboData[0], token[0]);
		strcpy_s(getLastgiboData[1], token[1]);
		strcpy_s(getLastgiboData[2], token[2]);
		strcpy_s(getLastgiboData[3], token[3]);
	}
}

void Board::insertColorPieces(Pieces* pieces, bool Color) 
{
	if (Color) 
		_bigColorPieces.push_back(pieces);
	else _smallColorPieces.push_back(pieces); 
}

std::vector<Pieces*> Board::GetEnemyData(bool Color) 
{
	if (Color)
		return _bigColorPieces;
	else
		return _smallColorPieces;
}