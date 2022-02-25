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
	std::vector < std::vector<Pieces*>> _mapData;

public:
	bool isThatAEmpty(int y,int x);


	int settingBoard(Pieces * pic,sPosition pos);




	//�� �̵�
	void piecesMove(sPosition chPos, sPosition relMove);


	void printBoard();


	//���Ļ��� ���� ���� ������ �ٰ��Դµ� üũ

public:
	bool canPromotion(sPosition piePos);

};

