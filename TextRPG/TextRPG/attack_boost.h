#pragma once
#include <string>
#include "Item.h"

class Character;//穿号 識情

class AttackBoost : public Item {
private:
	std::string name_;
	int attack_increase_;

public:
	AttackBoost();//持失切
	std::string name();//getter
	void Use(Character* character);
};
