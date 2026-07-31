#include "health_potion.h"

#include <iostream>

#include "character.h"

HealthPotion::HealthPotion( ) {
	name_ = "HP포션";
	health_restore_ = 50;
	price_ = 30;
}

std::string HealthPotion::name( ) {
	return name_;
}

void HealthPotion::Use(Character* character) {
	int prev_hp = character->hp( );
	character->set_hp(character->hp() + health_restore_);
	std::cout << name_ << "을 사용했습니다." << std::endl;
	std::cout << "HP: " << prev_hp << "->" << character->hp( ) << std::endl;
	std::cout << "────────────────────────────" << std::endl;
}
