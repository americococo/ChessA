#pragma once

#include "Pieces.h"
class King :public Pieces
{
public:
	King() { _oneMove = false; setup(); }
	~King() {}

	void setup();


//ĳ���� ���� �ƹ��͵� ���������� üũ
private:
	bool _oneMove;

public:
	void moveAction();
};

