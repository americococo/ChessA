#pragma once

#include "Pieces.h"
class King :public Pieces
{
public:
	King() { setup(); }
	~King() {}

	void setup();

};

