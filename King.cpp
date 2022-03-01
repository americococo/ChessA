#include "King.h"
#include "Board.h"

void King::setup()
{
	{
		sPosition ps;
		ps.x = 1;
		ps.y = 1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -1;
		ps.y = 1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 1;
		ps.y = -1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -1;
		ps.y = -1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 1;
		ps.y = 0;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = -1;
		ps.y = 0;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 0;
		ps.y = 1;
		relative_move.push_back(ps);
	}
	{
		sPosition ps;
		ps.x = 0;
		ps.y = -1;
		relative_move.push_back(ps);
	}
	_piescesCode = 'K';
	return;
}

void King::moveAction()
{
	_oneMove = true;
	return;
}

bool King::amIDanger()
{
	auto enmyData = Board::GetInstance()->GetEnemyData(!_color);



	for (int i = 0; i < enmyData.size(); i++)
	{
		int count = enmyData[i]->getRelativeMove().size();
		auto positionV = enmyData[i]->getRelativeMove();
		Pieces* enmP = enmyData[i];
		sPosition sePos;
		for (int j = 0; j < count; i++)
		{
			sePos = positionV[j];
			if (isEqualPosition(addPosition(sePos, enmP->getPos()), _curPosition))
			{
				printf("나 공격당한다.....(체크)\n");
				return true;
			}
		}

	}


	return true;
}