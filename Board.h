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
	char _mapData[8][8];

public:
	int settingBoard(Pieces * pic,sPosition pos);

	void move(Pieces* pic, sPosition sePos);


	//말 이동
	bool piecesMove(Pieces * pic, sPosition relMove);

	void printBoard();


	//앙파상을 위해 폰이 끝까지 다가왔는데 체크

public:
	bool canPromotion(Pieces * pic);


	Pieces* searchPieces(char picName, bool picColor, sPosition position);

	//기보데이터
private:
	char getLastgiboData[4][4];
public:
	void insertLastgiboData(char giboData[]);



	//적군 데이터 처리위한 함수
	std::vector<Pieces*> _bigColorPieces;
	std::vector<Pieces*> _smallColorPieces;

public:
	void insertColorPieces(Pieces* pieces, bool Color);

	std::vector<Pieces*> GetEnemyData(bool Color);
};

