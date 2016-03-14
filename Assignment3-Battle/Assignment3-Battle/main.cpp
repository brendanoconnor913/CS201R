#include <iostream>
#include <string>
#include "Utils.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;

// function to initialize characters w respective values
void SetupCharacters(Player& player, Enemy& enemy) {
	string name;
	int charactertype;
	int enemytype = GetRandom(1,3);

	// Getting a name for the player
	cout << "Please give your name:";
	cin.ignore();
	getline(cin, name);
	

	// Get the character type from the players
	cout << "Choose your character stats" << endl;
	cout << endl;
	cout << "Option \t Attack \t Defense" << endl;
	cout << "1 \t 5 \t 15" << endl;
	cout << "2 \t 15 \t 5" << endl;
	cout << "3 \t 10 \t 10" << endl;
	charactertype = GetUserInput(1, 3);
	
	switch (enemytype) {
	case 1:
		enemy.SetUp("enemy", 100, 5, 15);
		break;
	case 2:
		enemy.SetUp("enemy", 100, 15, 5);
		break;
	case 3:
		enemy.SetUp("enemy", 100, 10, 10);
		break;
	}

	switch (charactertype) {
	case 1:
		player.SetUp(name, 100, 5, 15);
		break;
	case 2:
		player.SetUp(name, 100, 15, 5);
		break;
	case 3:
		player.SetUp(name, 100, 10, 10);
		break;
	}

}

int main() {
	Player player;
	Enemy enemy;

	while (true) {
		// Loop until player is accepts stats
		SetupCharacters(player, enemy);
		player.DisplayStats();
		enemy.DisplayStats();
		
		cout << endl;
		cout << "Do you want to continue (1)Yes (2)No" << endl;
		if (GetUserInput(1,2) == 1) {
			break;
		}
		else {
			continue;
		}
	}

	// Continue looping until a character wins the battle
	int round = 0;
	while (player.GetHP() > 0 && enemy.GetHP() > 0)
	{
		int pAttack;
		int eAttack;

		// Display round information
		cout << "-------------------------------" << endl;
		cout << "ROUND " << round << endl;
		cout << endl;
		player.DisplayStats();
		enemy.DisplayStats();
		player.SelectAction();
		enemy.SelectAction();
		pAttack = player.GetAttack();
		enemy.GetHit(pAttack);
		eAttack = enemy.GetAttack();
		player.GetHit(eAttack);
		cout << endl;
		round++;
	}

	if (player.GetHP() <= 0) {
		cout << "You died...." << endl;
	}
	else {
		cout << "YOU DEFEATED YOUR OPPONENT!" << endl;
	}

return 0;
}