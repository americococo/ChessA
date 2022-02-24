#pragma once
#include <vector>
#include "position.h"

class Pieces
{
public:

	Pieces() { setup(); }
	~Pieces() {}



protected:
	std::vector<sPosition> relative_move;

public:
	virtual void setup() {}

	//테스트용 코드
	void print();

	bool isMoving(sPosition postion);


	//자기 식별용 
protected:
	char _piescesCode;
public:
	char getPiecesCode() { return _piescesCode; }

};