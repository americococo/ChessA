#pragma once
#include <vector>
class Pieces;

struct sPosition;
class Board
{
public:
	//mapdata �ʱ�ȭ 8 X 8 ������ ���缭
	Board();
	~Board() {}

private:
	char _mapData[8][8];

public:
	int settingBoard(Pieces * pic,sPosition pos);

	void move(Pieces* pic, sPosition sePos);


	//�� �̵�
	bool piecesMove(Pieces * pic, sPosition relMove);

	void printBoard();


	//���Ļ��� ���� ���� ������ �ٰ��Դµ� üũ

public:
	bool canPromotion(Pieces * pic);


	Pieces* searchPieces(char picName, bool picColor, sPosition position);

	//�⺸������
private:
	char getLastgiboData[4][4];
public:
	void insertLastgiboData(char giboData[]);



	//���� ������ ó������ �Լ�
	std::vector<Pieces*> _bigColorPieces;
	std::vector<Pieces*> _smallColorPieces;

public:
	void insertColorPieces(Pieces* pieces, bool Color);

	std::vector<Pieces*> GetEnemyData(bool Color);
};

