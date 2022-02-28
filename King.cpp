#include "King.h"

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
	//적군 진로 확인
	//적군 데이터 관리
	//적군 데이터 통해서 적군 다음턴 경로 검사
	//경로내에 왕이 존재할경우 true 반환
	//없으면 false 반환



	return true;
}