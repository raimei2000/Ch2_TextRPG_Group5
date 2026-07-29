#include "health_potion.h"

HealthPotion::HealthPotion() {
	name_ = "HP포션";
	health_restore_ = 50;
}

void HealthPotion::Use(Character* character) {
	character->set_hp(character->hp() + health_restore_);
}
