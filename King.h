#pragma once

#include "Pieces.h"
class King :public Pieces
{
public:
	King(bool color) { _color = color; _oneMove = false; setup(); }
	~King() {}

	void setup();


//캐슬링 위해 아무것도 움직였는지 체크
private:
	bool _oneMove;
	void moveAction();



public:

	bool amIDanger();

};

