#pragma once
#include "Pieces.h"
class Knight :public Pieces
{
public:
	Knight(bool color) { _color = color; setup(); }
	~Knight(){}

	void setup();

};

