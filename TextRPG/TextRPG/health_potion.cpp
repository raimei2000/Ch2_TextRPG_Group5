#include "health_potion.h"
#include "Character/character.h"

HealthPotion::HealthPotion() {
	name_ = "HP포션";
	health_restore_ = 50;
}

std::string HealthPotion::name() {
	return name_; 
}

void HealthPotion::Use(Character* character) {
	character->set_hp(character->hp() + health_restore_);
}
