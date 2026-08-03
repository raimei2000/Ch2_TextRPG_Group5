#pragma once
#include <string>

class Character;

class Item {
protected:
	const std::string name_;
	const int price_;
public:
	std::string name( ) const { return name_; }
	int price( ) const { return price_; }
	virtual void Use(Character* character) = 0;
	Item(const std::string& name, int price);
	virtual ~Item( ) = default;
};