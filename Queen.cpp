#include "Queen.h"

void Queen::setup()
{
	for(int i=1;i<8;i++)
	{
		{
			sPosition ps;
			ps.x = i;
			ps.y = i;
			relative_move.push_back(ps);
		}
		{
			sPosition ps;
			ps.x = -1 * i;
			ps.y = i;
			relative_move.push_back(ps);
		}
		{
			sPosition ps;
			ps.x = i;
			ps.y = -1 * i;
			relative_move.push_back(ps);
		}
		{
			sPosition ps;
			ps.x = -1 * i;
			ps.y = -1 * i;
			relative_move.push_back(ps);
		}
		{
			sPosition ps;
			ps.x = i;
			ps.y = 0;
			relative_move.push_back(ps);
		}
		{
			sPosition ps;
			ps.x = -i;
			ps.y = 0;
			relative_move.push_back(ps);
		}
		{
			sPosition ps;
			ps.x = 0;
			ps.y = i;
			relative_move.push_back(ps);
		}
		{
			sPosition ps;
			ps.x = 0;
			ps.y = -i;
			relative_move.push_back(ps);
		}
	}
	_piescesCode = 'Q';
	return;
}