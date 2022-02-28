#include "position.h"
bool isEqualPosition(sPosition asd, sPosition qwe)
{
	if (asd.x != qwe.x)
		return false;
	if (asd.y != qwe.y)
		return false;

	return true;
}
sPosition addPosition(sPosition asd, sPosition qwe)
{
	sPosition asdzxc;
	asdzxc.y= asd.y + qwe.y;
	asdzxc.x = asd.x + qwe.y;
	return asdzxc;
}