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
//	//대충 자기 위치에다가 
//	//비숍,나이트,룩,퀸 선택한것을 생성후
//	//자기자신 삭제
//	//delete this;
//
//	//sPosition ps;
//
//	//return ps;
//}
