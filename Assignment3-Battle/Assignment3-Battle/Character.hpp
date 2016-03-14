#ifndef _Character
#define _Character

#include <string>

using namespace std;

class Character {
public:
	void SetUp(const string name, int hp, int atk, int def);
	void DisplayStats();
	void SelectAttack() {};
	int GetAttack();
	void GetHit(int attack);
	int GetHP();
protected:
	enum AttackType {
		OFFENSIVE = 1,
		DEFENSIVE = 2
	};
	int m_hp;
	int m_atk;
	int m_def;
	string m_name;
	AttackType m_attackType;
};

#endif
