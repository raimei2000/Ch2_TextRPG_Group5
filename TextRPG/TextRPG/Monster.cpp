#include "Monster.h"
#include <string>

Monster::Monster(std::string name, int health, int attack)
	:
	name(name), health(health), attack(attack)
{

}

//getter
std::string Monster::Name()
{
	return name;
}
int Monster::Health()
{
	return health;
}
int Monster::Attack()
{
	return attack;
}


//ÇÔ¼ö
void takeDamage(int damage)
{
	
}
