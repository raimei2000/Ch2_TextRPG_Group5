#include "Character.h"

Player::Player(std::string Name, int HP, int Power, int exp) {
	this->Name = Name;
	this->HP = HP;
	this->Power = Power;
	this->Level = 1;
	this->MaxLevel = 10;
	this->Exp = 0;
	this->MaxExp = 100;
}

int Player ::getHP() {
	return HP;
}

void Player::setHP(int newHP) {
	HP = newHP;
}

void Player::setName(const std::string& newName) {
	Name = newName;
}

int Player::getPower() {
	return Power;
}

