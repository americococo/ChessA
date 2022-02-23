#pragma once
#include "Pieces.h"
class Bishop :public Pieces
{
public:
	Bishop() { setup(); }
	~Bishop(){}

	void setup();
};

