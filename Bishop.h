#pragma once
#include "Pieces.h"
class Bishop :public Pieces
{
public:
	Bishop(bool color) { _color; setup(); }
	~Bishop(){}

	void setup();
};

