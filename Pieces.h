#pragma once
#include <vector>
#include "position.h"

class Pieces
{
public:

	Pieces() { setup(); }
	~Pieces() {}



protected:
	std::vector<sPosition> relative_move;

public:
	virtual void setup() {}

	//�׽�Ʈ�� �ڵ�
	void print();

	bool isMoving(sPosition postion);
};