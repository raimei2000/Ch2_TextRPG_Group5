#include "attack_boost.h"

AttackBoost::AttackBoost() {
	name_ = "공격력 부스트";
	attack_increase_ = 10;
}

void AttackBoost::Use(Character* character) {
	character->set_power(character->power()+attack_increase_);
}
