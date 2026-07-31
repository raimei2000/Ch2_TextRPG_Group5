#pragma once
#include "item.h"

#include <string>

class Character;

class HealthPotion : public Item {
private:
	int health_restore_;

public:
	HealthPotion();
	void Use(Character* character);
};
