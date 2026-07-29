#pragma once
#include <string>
#include "Item.h"

class Character;//穿号識情

class HealthPotion : public Item {
private:
	std::string name_;
	int health_restore_;
public:
	HealthPotion();//持失切
	std::string name() { return name_; };//getter
	void Use(Character* character);
};
