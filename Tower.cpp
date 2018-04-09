#include "Tower.h"

Tower::Tower()
{
	Health = 0;
	FirePower = 0;
	UnpavedDistance = 30;
}
Tower::~Tower()
{

}
void Tower::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}
void Tower::DecrementUnpavedDistance(double p)
{
	UnpavedDistance -= (p > 0) ? p : 0;
	if (UnpavedDistance < 2)
		UnpavedDistance = 2;
}

double Tower::GetHealth() const
{
	return Health;
}
double Tower::GetFirePower()const
{
	return FirePower;
}
double Tower::GetUnpavedDistance()const
{
	return UnpavedDistance;
}
bool Tower::IsKilled()const
{
	return Health == 0;
}
void Tower::SetFirePower(double f)
{
	FirePower = (f > 0) ? f : 0;
}
