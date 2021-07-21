#pragma once
#include <iostream>
#include <time.h>

using namespace std;

class Player
{
	string playerName;
	int armorStrength;
	int weaponStrength;
	int health;

public:
	Player(string, int, int);
	
	bool setArmor(int);
	bool setWeapon(int);
	void setHealth(int);

	int getArmor() const { return armorStrength; }
	int getWeapn() const { return weaponStrength; }
	int getHealth() const { return health; }

	void takeDamage(int);
	int attack();
	void printPlayer();
};

