#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

// Enemy is the base class of each type of enemy
// Enemy is an abstract class.
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	double FirePower; // Enemy firepower
	int ArrivalTimeStamp; // Arrival time
	int ReloadPeriod; // Reload period of enemy
	int FD, KD, LT;    //such that :
					   //FD : the time elapsed until an enemy is first shot by a tower
					   //KD : the time elapsed between first time a tower shoots the enemy and its kill time 
					   //LT : the total time an enemy stays alive until being killed
	bool FirstShot;    // Always false till the first shot
	bool Killed;       // True if enemy is killed

	bool IsShot()const;            // check if enemy was shot before
	void SetShot(int t);      // set FirstShot true && set FD
	void SetKilled(int t);    // set killed true && set KD , LT
	virtual void DecrementHealth(double f);
	int RemainingTimeforShot(int t)const;
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy();
	virtual ~Enemy();

	// Get funs
	color GetColor() const;
	REGION GetRegion() const;
	int GetDistance() const;
	double GetHealth()const;
	double GetFirePower()const;
	int GetArrivalTimeStamp()const; 
	int GetReloadPeriod()const;
	int GetFD()const;
	int GetKD()const;
	int GetLT()const;
	int GetID()const;

	//Set funcs
	void SetDistance(int d);
	void SetID(int i);
	void SetHealth(double h);
	void SetFirePower(double f);
	void SetArrivalTimeStamp(int t);
	void SetReloadPeriod(int r);
	void SetRegion(REGION R);
	virtual void SetColor();

	// Utility funcs
	void DecrementDist();
	bool IsReloadPeriod(int t)const;     // Returns if the enemy is in its reload period
	void Attacked(double f, int t);   // Decreases health of the enemy
	bool IsKilled()const;


	// Virtual Functions: ----------------

	//virtual void Move() = 0;	    //All enemies can move
	//virtual void Attack() = 0;	//All enemies can attack (attacking is paving or shooting)

	//
	// TODO: Add More Member Functions As Needed
	//

};

