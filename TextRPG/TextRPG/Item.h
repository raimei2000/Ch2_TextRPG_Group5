#pragma once
#include <string>

class Player;

class Item {
public:
	virtual std::string name() = 0;
	virtual void use(Player* player) = 0;
};