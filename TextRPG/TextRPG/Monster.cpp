#include "monster.h"

#include <string>


Monster::Monster(std::string name, int health, int attack)
	:
	name_(name), health_(health), attack_(attack)
{

}

//getter
std::string Monster::name()
{
	return name_;
}
int Monster::health()
{
	return health_;
}
int Monster::attack()
{
	return attack_;
}

//setter
void Monster::set_name(std::string name)
{
	this->name_ = name;
}
void Monster::set_health(int health)
{
	this->health_ = health;
}
void Monster::set_attack(int attack)
{
	this->attack_ = attack;
}



//함수
void Monster::TakeDamage(int damage)
{

}
