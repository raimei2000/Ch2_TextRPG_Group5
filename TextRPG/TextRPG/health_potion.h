#pragma once
#include "item.h"

#include <string>

class Character;

class HealthPotion : public Item {
private:
	int health_restore_;
	static const int kPrice = 30;

public:
	HealthPotion();
	void Use(Character* character);
	int price( ) const override;
};
