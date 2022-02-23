#include "Board.h"
#include "Pieces.h"

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