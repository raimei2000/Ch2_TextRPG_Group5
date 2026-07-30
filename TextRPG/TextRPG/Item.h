#pragma once
#include <string>

class Character;

class Item {
public:
	virtual std::string name() = 0;
	virtual void Use(Character* character) = 0;
	virtual ~Item( ) = default;
};
