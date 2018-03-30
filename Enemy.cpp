#include "Enemy.h"


Enemy::Enemy()
{
	ArrivalTimeStamp = 0;
	FirePower = 0;
	ReloadPeriod = 0;
	Health = 0;
	Distance = MaxDistance;
	FD = 0;
	KD = 0;
	LT = 0;
}

Enemy::~Enemy()
{
}


color Enemy::GetColor() const
{
	return Clr;
}

REGION Enemy::GetRegion() const
{
	return Region;
}

void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}
int Enemy::GetID()const
{
	return ID;
}
// Added funcs

// set funcs

void Enemy::SetID(int i)
{
	ID = i;
}
double Enemy::GetHealth()const
{
	return Health;
}
double Enemy::GetFirePower()const
{
	return FirePower;
}
int Enemy::GetArrivalTimeStamp()const
{
	return ArrivalTimeStamp;
}
int Enemy::GetReloadPeriod()const
{
	return ReloadPeriod;
}
int Enemy::GetFD()const
{
	return FD;
}
int Enemy::GetKD()const
{
	return KD;
}
int Enemy::GetLT()const
{
	return LT;
}

bool Enemy::IsReloadPeriod(int t)const
{
	return ((t - ArrivalTimeStamp) % ReloadPeriod != 0);
}
void Enemy::Attacked(double f, int t)
{
	if (!IsShot())
		SetShot(t);
	DecrementHealth(f);
	if (Health <= 0)
		SetKilled(t);
}
int Enemy::RemainingTimeforShot(int t)const
{
	if ((t - ArrivalTimeStamp) % ReloadPeriod != 0)
		return (ReloadPeriod - (t - ArrivalTimeStamp) % ReloadPeriod);
	else
		return 0;
}
void Enemy::SetKilled(int t)
{
	Killed = true;
	KD = t - FD;
	LT = KD + FD;
}
bool Enemy::IsKilled()const
{
	return Killed;
}
bool Enemy::IsShot()const
{
	return FirstShot;
}
void Enemy::SetShot(int t)
{
	FirstShot = true;
	FD = t - ArrivalTimeStamp;
}



void Enemy::SetHealth(double h)
{
	Health = (h > 0) ? h : 0;
}
void Enemy::SetFirePower(double f)
{
	FirePower = (f > 0) ? f : 0;
}
void Enemy::SetArrivalTimeStamp(int t)
{
	ArrivalTimeStamp = (t > 0) ? t : 0;
}
void Enemy::SetReloadPeriod(int r)
{
	ReloadPeriod = (r > 0) ? r : 0;
}
void Enemy::SetRegion(REGION R)
{
	Region = R;
}
void Enemy::SetColor()
{}
void Enemy::DecrementHealth(double f)
{
	Health -= f / Distance;
}

