#pragma once
#include <iostream>
#include <string>

class Player {
protected:
	std::string Name;
	int Level;
	int MaxLevel;
	int HP;
	int Power;
	int Exp;
	int MaxExp;

public:
	Player(std::string Name, int HP, int Power, int exp);

	int getHP();
	void setHP(int newHP);
	void setName(const std::string& newName);
	int getPower();
	int gainExp(int amount);

	virtual void attack(Monster* monster) = 0;
	virtual ~Player() {};
};