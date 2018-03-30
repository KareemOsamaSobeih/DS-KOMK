#include "ShieldedFighterEnemy.h"

ShieldedFighterEnemy::ShieldedFighterEnemy() : Enemy()
{
}

ShieldedFighterEnemy::~ShieldedFighterEnemy()
{
}
void ShieldedFighterEnemy::SetColor()
{
	Clr = ORANGERED;
}
void ShieldedFighterEnemy::DecrementHealth(double f)
{
	Health -= f / 2 / Distance;
}
void  ShieldedFighterEnemy::SetC1(double c1)
{
	C1 = c1;
}
void ShieldedFighterEnemy::SetC2(double c2)
{
	C2 = c2;
}
void ShieldedFighterEnemy::SetC3(double c3)
{
	C3 = c3;
}
double ShieldedFighterEnemy::GetC1()
{
	return C1;
}
double ShieldedFighterEnemy::GetC2()
{
	return C2;
}
double ShieldedFighterEnemy::GetC3()
{
	return C3;
}
double ShieldedFighterEnemy::GetPriority(int t)const
{
	return (FirePower * C1 / Distance + C2 / RemainingTimeforShot(t) + Health * C3);
}