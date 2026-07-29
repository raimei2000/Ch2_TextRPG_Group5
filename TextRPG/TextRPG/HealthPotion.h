#pragma once
#include <string>
#include "Item.h"

class Player;

class HealthPotion : public Item {
private:
	std::string name_;
	int health_restore_;
public:
	HealthPotion();
	std::string name() { return name_; };
	void use(Player* player);
};