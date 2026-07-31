#include "attack_boost.h"

#include <iostream>

#include "character.h"

AttackBoost::AttackBoost() {
	name_ = "공격력 부스트";
	attack_increase_ = 10;
}

std::string AttackBoost::name() {
	return name_;
}

void AttackBoost::Use(Character* character) {
	int prev_power_ = character->power( );
	character->AddTemporaryPowerBonus(attack_increase_);
	std::cout << character->name( ) << "가 " << name_ << "를 사용했습니다." << std::endl;
	std::cout << "공격력: " << prev_power_ << " -> " << character->power( );
}
