#include <iostream>
#include "Player.hpp"
#include "Utils.hpp"
using namespace std;

// Get the attack type for the player and set it to m_attackType
void Player::SelectAction() {
	int choice;
	cout << "Attack Types (1)Offensive (2)Defenseive" << endl;
	choice = GetUserInput(1, 2);
	cout << endl;

	switch (choice) {
	case 1:
		m_attackType = OFFENSIVE;
		break;
	case 2:
		m_attackType = DEFENSIVE;
		break;
	default:
		cout << "Invalid option..." << endl;
	}
}