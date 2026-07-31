#include "attack_boost.h"

#include <iostream>

#include "character.h"

AttackBoost::AttackBoost() {
	name_ = "공격력 부스트";
	attack_increase_ = 10;
	price_ = 40;
}

void AttackBoost::Use(Character* character) {
	int prev_power = character->power( );
	character->AddTemporaryPowerBonus(attack_increase_);
	std::cout << name_ << "를 사용했습니다." << std::endl;
	std::cout << "공격력: " << prev_power << " -> " << character->power( )<< std::endl;
	std::cout << "============================" << std::endl;
}
