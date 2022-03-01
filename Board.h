#pragma once
#include <vector>
class Pieces;
class King;
struct sPosition;


class Board
{
	

public:
	//mapdata 초기화 8 X 8 사이즈 맞춰서
	~Board() {}
public:
	static Board * GetInstance() 
	{
		if (_instance == nullptr)
		{
			_instance = new Board();
		}
		return _instance;
	}

private:
	Board();
	char _mapData[8][8];
	static Board * _instance;

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

private:
	King * Bigking;
	King * smallking;
public:
	void InsertBigKing(King* pic) { Bigking = pic; }
	void InsertSmallKing(King* pic) { smallking = pic; }


	King * getKingInfo(bool color) { return color ? Bigking : smallking; }

};

