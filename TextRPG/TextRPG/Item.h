#pragma once
#include <string>

class Character;

class Item {
public://순수 가상 함수
	virtual std::string name() = 0;
	virtual void Use(Character* character) = 0;
};
