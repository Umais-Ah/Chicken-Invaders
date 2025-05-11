#pragma once
#include "chickens.h"
class GunChicken :
	public Chickens
{
public:
	GunChicken(void);
	~GunChicken(void);
	void movement();
	bool beamStrike(float,float);
private:
	int eggDropCount;
};



