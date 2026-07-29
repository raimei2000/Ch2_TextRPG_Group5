#include <string>
#include "Monster.h"


Monster::Monster(std::string name_, int health_, int attack_)
	:
	name_(name_), health_(health_), attack_(attack_)
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
void Monster::set_name(std::string name_)
{
	this->name_ = name_;
}
void Monster::set_health(int health_)
{
	this->health_ = health_;
}
void Monster::set_attack(int attack_)
{
	this->attack_ = attack_;
}



//ÇÔ¼ö
void Monster::takeDamage(int damage)
{
	
}
