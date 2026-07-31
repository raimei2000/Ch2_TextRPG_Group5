#pragma once
#include "item.h"

#include <string>

class Character;

class AttackBoost : public Item {
private:
	std::string name_;
	int attack_increase_;
	int price_;

public:
	AttackBoost();
	std::string name();
	int price();
	void Use(Character* character);
};
