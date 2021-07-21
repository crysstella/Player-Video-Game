#include "Player.h"
#include <string>

//using namespace std;

Player::Player(string name, int armor, int weapon)
{
	playerName = name;
	armorStrength = armor;
	weaponStrength = weapon;
	health = 100;
}

bool Player::setArmor(int armor)
{
	if ((armor < 0) || (armor > 100))
	{
		cout << "The armor should be larger than 0 and smaller than 100!" << endl;
		return false;
	}
	else
	{
		armorStrength = armor;
	}
	return true;
}

bool Player::setWeapon(int weapon)
{
	if ((weapon < 0) || (weapon > 100))
	{
		cout << "The weapon should be larger than 0 and smaller than 100!" << endl;
		return false;
	}
	else
	{
		weaponStrength = weapon;
	}
	return true;
}

void Player::takeDamage(int damageTaken)
{
	damageTaken = attack();

	if (armorStrength > 0)
	{
		if (armorStrength < damageTaken)
		{
			armorStrength = 0;
		}
		else
		{
			armorStrength -= damageTaken;
		}
	}
	else if (armorStrength == 0)
	{
		health -= damageTaken;
		if (health < damageTaken)
		{
			health = 0;
			cout << "You have died!!!" << endl;
			cout << endl;
		}
	}

}

int Player::attack()
{
	int randomAttack = (rand() % weaponStrength) + 1;

	cout << "You attack " << randomAttack << " damage!" << endl;
	cout << endl;

	return randomAttack;
}

void Player::printPlayer()
{
	cout << "Player name: " << playerName << endl;
	cout << "Health: " << health << endl;
	cout << "Armor: " << armorStrength << endl;
	cout << "Weapon strength: " << weaponStrength << endl;

	
}