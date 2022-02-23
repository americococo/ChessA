#pragma once
#include "Pieces.h"
class Queen : public Pieces
{
public:
	Queen() { setup(); }
	~Queen(){}


	void setup();
};

