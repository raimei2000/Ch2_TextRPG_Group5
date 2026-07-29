#pragma once
#include <string>


class Monster
{

public:
	std::string name_;
	int health_;
	int attack_;
	// 순수 가상 함수
	Monster(std::string name_, int health_, int attack_);
	
    virtual void Attack() = 0;

	//getter
	std::string name();
	int health();
	int attack();

	//setter
	void set_name(std::string name_);
	void set_health(int health_);
	void set_attack(int attack_);

	//함수
	void takeDamage(int damage);
};

    
