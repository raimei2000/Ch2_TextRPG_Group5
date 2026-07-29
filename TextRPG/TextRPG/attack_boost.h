#pragma once
#include <string>
#include "Item.h"

class Character;

class AttackBoost : public Item {
private:
	std::string name_;
	int attack_increase_;

public:
	AttackBoost();
	std::string name();
	void Use(Character* character);
};
