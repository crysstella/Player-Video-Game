/*Write a class ​Player​ to be used in a video game.An instance of this classwill represent the player’s character.

The constructor should accept three arguments for : The player’s name, armor strength, and weapon strength which should be assigned to membervariables.
A fourth member variable ​health​ should be set to 100.

Create setters and getters for armor strengthand weapon strength(since theplayer might acquire new armor and a new weapon).
Do not allow the clientto create a player with armor or weapon less than 0 or greater than 100.

Define a member function takeDamage to call on a Player object when theyare attacked.Its parameter contains how much damage the player takes.

If the player has any armor left, decrement the armor by the amount ofdamage.If an attack brings the armor below 0, set armor to 0.
If the player 0 armor left, decrement health by the amount of damage.If health is brought to 0 (or below) print that they have died.

The member function ​attack​ is called on a Player object when the playerattacks.A random int is generated between 1 and
the player’s weaponstrength(refer to lecture 8 slides 12 - 20 for rand).A message indicating howmuch the player attacks for printsand the attack value should be returned.

Finally, define a member function printPlayer which should print the currentstate of the player(name, health, armor, and weapon).

Write a simple main function which creates a Player objectand tests itsvarious methods.Submit Source.cpp, Player.cpp, and Player.h
*/

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

int main()
{
	string name;
	int weapon, armor;

	bool armor_check;
	bool weapon_check;

	cout << "Enter a player's name: " << endl;
	getline(cin, name);

	do
	{
		cout << "Enter the strength of an armor: " << endl;
		cin >> armor;

		cout << "Enter the strength of a weapon: " << endl;
		cin >> weapon;

		Player player(name, armor, weapon);
		armor_check = player.setArmor(armor);
		weapon_check = player.setWeapon(weapon);

		cout << endl;

	} while ((armor_check == false) || (weapon_check == false));
	
	Player player(name, armor, weapon);
	srand(time(0));

	while (player.getHealth() > 0)
	{
		player.takeDamage(0);
		
		//print each time the player is attacked
		player.printPlayer();
	}

	return 0;
}