// konzultacije.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
class IllegalEnemyException :public std::runtime_error {
public:
	IllegalEnemyException(string);
};
IllegalEnemyException::IllegalEnemyException(string message) :runtime_error(message) {}
class Enemy {
	string Name;
	int Health;
	int AttackDamage;
public:
	int getAttackDamage()const { return AttackDamage; }
	int getHealth()const { return Health; }
	string getName()const { return Name; }
	virtual void heal(int amount);
	virtual void takeDamage(int amount) = 0;
	Enemy(string name, int health, int attackdamage) :Name(name), Health(health), AttackDamage(attackdamage) {}
};
void Enemy::heal(int amount) {
	if (Health == 0)
		throw "Dead";
	Health += amount;
}
class ArmoredEnemy :public Enemy {
	double HitChance;
	int Armor;
public:
	ArmoredEnemy(string name, int health, int attackdamage, double hitchance, int armor) :Enemy(name, health, attackdamage), HitChance(hitchance), Armor(armor) {}
	virtual void takeDamage(int amount);
};
void ArmoredEnemy::takeDamage(int amount) {
	double r = ((double)rand() / (RAND_MAX));
	if (r > HitChance) {
		while (Armor > 0)
			Armor -= amount;
		//kako napraviti da nakon oklopa oduzme zdravlje
	}
}
Enemy createEnemies(int n) {

}
int main()
{
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
