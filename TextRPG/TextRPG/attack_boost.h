#pragma once
#include "item.h"

#include <string>

class Character;

class AttackBoost : public Item {
private:
	int attack_increase_;


public:
	AttackBoost();
	void Use(Character* character);
};
