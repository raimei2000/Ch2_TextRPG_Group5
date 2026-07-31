#pragma once
#include "item.h"

#include <string>

class Character;

class HealthPotion : public Item {
private:
	std::string name_;
	int health_restore_;
	int price_;

public:
	HealthPotion();
	std::string name();
	void Use(Character* character);
};
