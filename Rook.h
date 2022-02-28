#pragma once
#include "Pieces.h"
class Rook :public Pieces
{
public:
	Rook(bool color) { _color = color; setup(); }
	~Rook(){}

	void  setup();


private:
	bool _oneMove;
	void moveAction();
};

