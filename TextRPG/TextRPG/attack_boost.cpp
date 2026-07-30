#include "attack_boost.h"
#include "character.h"

AttackBoost::AttackBoost() {
	name_ = "공격력 부스트";
	attack_increase_ = 10;
}

std::string AttackBoost::name() {
	return name_;
}

void AttackBoost::Use(Character* character) {
	character->set_power(character->power()+attack_increase_);
}
