#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
}

void Castle::SetTowersHealth(double h)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetHealth(h);
	}
}
void Castle::SetTowersFirePower(double f)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetFirePower(f);
	}
}
bool Castle::CastleLose()const
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		if(!Towers[i].IsKilled())
			return false;
	}
	return true;
}
