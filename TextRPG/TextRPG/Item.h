#pragma once
#include <string>

class Character;

class Item {
protected:
	std::string name_;
	int price_;
public:
	std::string name( ) { return name_; }
	int price( ) { return price_; }
	virtual void Use(Character* character) = 0;
	virtual ~Item() = default;
};
