#pragma once

#include "Pieces.h"
class King :public Pieces
{
public:
	King(bool color) { _color = color; _oneMove = false; setup(); }
	~King() {}

	void setup();


//ĳ���� ���� �ƹ��͵� ���������� üũ
private:
	bool _oneMove;
	void moveAction();



public:

	bool amIDanger();

};

