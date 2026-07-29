#pragma once
#include <string>
#include "Item.h"

class Player;

class AttackBoost : public Item {
private:
	std::string name_;
	int attack_increase_;
public:
	AttackBoost();
	std::string name() { return name_; };
	void use(Player* player);
};