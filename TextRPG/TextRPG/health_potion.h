#pragma once
#include <string>
#include "item.h"

class Character;

class HealthPotion : public Item {
private:
	std::string name_;
	int health_restore_;

public:
	HealthPotion();
	std::string name();
	void Use(Character* character);
};
