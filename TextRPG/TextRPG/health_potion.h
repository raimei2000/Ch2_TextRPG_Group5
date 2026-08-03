#pragma once
#include "item.h"

#include <string>

class Character;

class HealthPotion : public Item {
private:
	int health_restore_;

public:
	static const int kPrice = 30;

	HealthPotion();
	void Use(Character* character);
	int price( ) const override;
};
