#pragma once
#include <vector>
#include <cctype>

#include "position.h"

class Pieces
{
public:
	Pieces() { setup(); }
	Pieces(bool color) { _color = color; setup(); }
	~Pieces() { relative_move.clear(); }



protected:
	std::vector<sPosition> relative_move;
	bool _color;

public:
	bool getColor() { return _color; }
	std::vector<sPosition> getRelativeMove();


public:
	virtual void setup() {}

	//�׽�Ʈ�� �ڵ�
	void print();

	virtual bool isMoving(sPosition postion);


	//�ڱ� �ĺ��� 
protected:
	char _piescesCode;
	sPosition _curPosition;



public:
	void settingPosition(sPosition pos);

	sPosition getPos() { return _curPosition; }

public:
	char getPiecesCode() { return _piescesCode; }

	char PiecesPrintCode(){ if (_color)return _piescesCode; else return tolower(_piescesCode); }
	

public:
	virtual void moveAction() {}




};
