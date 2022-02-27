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

public:
	virtual void setup() {}

	//테스트용 코드
	void print();

	virtual bool isMoving(sPosition postion);


	//자기 식별용 
protected:
	char _piescesCode;
public:
	char getPiecesCode() {if (_color)return _piescesCode;else return tolower(_piescesCode);}

	
	
};
