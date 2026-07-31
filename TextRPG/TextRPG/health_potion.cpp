#include "health_potion.h"

#include <iostream>
#include <algorithm>

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
	int healed_hp_ = std::min(character->hp( ) + health_restore_, character->max_hp( ));
	std::cout << name_ << "를 사용했습니다." << std::endl << "HP: " << prev_hp_ << "->" << healed_hp_ << std::endl;
	character->set_hp(healed_hp_);
}
