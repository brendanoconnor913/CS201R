#include <string>
#include <iostream>
#include "Character.hpp"
#include "Utils.hpp"
using namespace std;

void Character::SetUp(const string name, int hp, int atk, int def) {
	// Initialize the variables passed while initializing
	m_name = name;
	m_hp = hp;
	m_atk = atk;
	m_def = def;
}


void Character::DisplayStats() {
	// Output each character's stats
	cout << "\t" << m_name << " has hp: " << m_hp << ", attack: " << m_atk
		<< ", defense: " << m_def << endl;
	cout << endl;
}

int Character::GetAttack() {
	// get the value of attack depending on player's attack type
	if (m_attackType == 1) {
		int offenAtck = GetRandom(1, 3) + m_atk;
		cout << m_name << " does an OFFENSIVE attack with " <<
			offenAtck << " damage." << endl;
		return offenAtck;
	}
	else {
		cout << m_name << " does an DEFENSIVE attack with " << m_atk
			<< " damage." << endl;
		return m_atk;
	}
}

void Character::GetHit(int attack) {
	// Determine the damage based on opponent's param attack	
	if (m_attackType == 1) {
		int damage;
		damage = attack - m_def;
		// make sure attack isn't adding to opponents hp
		if (damage < 0) {
			damage = 0;
		}
		m_hp -= damage;
		cout << m_name << " is hit and " << damage
			<< " damage is delt!" << endl;
	}
	else if (m_attackType == 2) {
		int damage;
		damage = attack - m_def - GetRandom(1, 3);
		// make sure attack isn't adding to opponents hp
		if (damage < 0) {
			damage = 0;
		}
		m_hp -= damage;
		cout << m_name << " is hit and " << damage
			<< " damage is delt!" << endl;
	}
	
};

int Character::GetHP() {
	return m_hp;
}