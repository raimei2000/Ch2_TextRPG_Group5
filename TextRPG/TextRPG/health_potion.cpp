#include "health_potion.h"

#include <iostream>

#include "character.h"

HealthPotion::HealthPotion( ) {
	name_ = "HP포션";
	health_restore_ = 50;
}

std::string HealthPotion::name( ) {
	return name_;
}

void HealthPotion::Use(Character* character) {
	int prev_hp_ = character->hp( );
	character->set_hp(character->hp() + health_restore_);
	std::cout << character->name() <<"가(이) " << name_ << "를 사용했습니다." << std::endl << "HP: " << prev_hp_ << "->" << character->hp() << std::endl;
	std::cout << "============================" << std::endl;
}
