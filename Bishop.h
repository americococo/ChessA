#pragma once
#include "Pieces.h"
class Bishop :public Pieces
{
public:
	Bishop(bool color) { _color = color; setup(); }
	~Bishop(){}

	void setup();
};

