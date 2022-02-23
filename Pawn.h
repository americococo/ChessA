#pragma once
#include "Pieces.h"
class Pawn : public Pieces
{
public:
	Pawn() { setup(); }
	~Pawn() {}

	void setup();
	//sPosition promotion();
};

