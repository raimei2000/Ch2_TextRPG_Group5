#pragma once
#include <string>


class Monster
{

private:
	std::string name_;
	int health_;
	int attack_;


public:
	// 순수 가상 함수
	Monster(std::string name, int health, int attack);

	virtual void Attack() = 0;

	//getter
	std::string name();
	int health();
	int attack();

	//setter
	void set_name(std::string name);
	void set_health(int health);
	void set_attack(int attack);

	//함수
	void TakeDamage(int damage);
};


