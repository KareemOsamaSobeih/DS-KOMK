#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"

class Castle
{
	Tower Towers[NoOfRegions];
	
public:

	Castle();
	void SetTowersHealth(double h);
	void SetTowersFirePower(double f);
	bool CastleLose()const;
	
};
