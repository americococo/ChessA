#include "position.h"
bool isEqualPosition(sPosition asd, sPosition qwe)
{
	if (asd.x != qwe.x)
		return false;
	if (asd.y != qwe.y)
		return false;

	return true;
}