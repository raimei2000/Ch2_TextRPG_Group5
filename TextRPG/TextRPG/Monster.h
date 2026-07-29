#pragma once
#include <string>


class Monster
{

public:
	std::string name;
	int health; 
	int attack;
	Monster(std::string name, int health, int attack);
	

	//getter
	std::string Name();
	int Health();
	int Attack();


	//ÇÔ¼ö
	void takeDamage(int damage);
};