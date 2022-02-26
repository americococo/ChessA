#pragma once
#include "Pieces.h"
class Pawn : public Pieces
{
public:
	Pawn(bool color) { _color = color; _oneMove = false; setup(); }
	~Pawn() {}

	void setup();
	

	Pieces * Promotion();

private:
	bool _oneMove;
public:
	bool isMoving(sPosition postion);


private:
	void moveAction();
};

