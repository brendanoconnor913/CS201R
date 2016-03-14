#include <iostream>
#include "Enemy.hpp"
#include "Utils.hpp"
using namespace std;

// Select a random attack type for enemy's m_attackType
void Enemy::SelectAction() {
	int choice = GetRandom(1, 2);

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