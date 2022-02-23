#pragma once
#include <vector>
class Pieces;

struct sPosition;
class Board
{
public:
	//mapdata 초기화 8 X 8 사이즈 맞춰서
	Board();
	~Board() {}

private:
	std::vector < std::vector<Pieces*>> _mapData;

public:
	bool isThatAEmpty(int y,int x);


	int settingBoard(Pieces * pic,sPosition pos);

};

