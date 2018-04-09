#pragma once
class Tower
{
	double Health;
	double FirePower;
	double UnpavedDistance;

public:

	Tower();    // set data members to zero
	~Tower();
	void SetHealth(double h);   
	void SetFirePower(double f);
	void DecrementUnpavedDistance(double p);

	double GetHealth() const;
	double GetFirePower()const;
	double GetUnpavedDistance()const;
	bool IsKilled()const;    //return killed if health = 0


};

