#include "Pawn.h"

void Pawn::setup()
{
	{
		sPosition ps;
		ps.x = 0;
		ps.y = 2;
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
	return;
}

//sPosition Pawn::promotion()
//{
//	//���� �ڱ� ��ġ���ٰ� 
//	//���,����Ʈ,��,�� �����Ѱ��� ������
//	//�ڱ��ڽ� ����
//	//delete this;
//
//	//sPosition ps;
//
//	//return ps;
//}
