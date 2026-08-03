#pragma once
#include "item.h"

#include <string>

class Character;

class AttackBoost : public Item {
private:
	int attack_increase_;

public:
	static const int kPrice = 40;

	AttackBoost();
	void Use(Character* character);
	int price( ) const override;
	void PrintItemInfo( ) const override;
};
