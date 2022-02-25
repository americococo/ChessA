#pragma once
#include "Pieces.h"
class Queen : public Pieces
{
public:
	Queen(bool color) { _color = color; setup(); }
	~Queen(){}


	void setup();
};

