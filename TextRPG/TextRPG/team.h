#pragma once
#include <string>

class Character;

class Item {
protected:
	const std::string name_;
public:
	std::string name( ) const { return name_; }
	virtual int price( ) const = 0;
	virtual void Use(Character* character) = 0;
	Item(const std::string& name);
	virtual ~Item( ) = default;
	virtual void PrintItemInfo( ) const = 0;
};