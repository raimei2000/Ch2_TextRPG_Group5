#include "attack_boost.h"

#include <iostream>

#include "character.h"

AttackBoost::AttackBoost( ) : Item("공격력 부스트"), attack_increase_(10) {}

void AttackBoost::Use(Character* character) {
	int prev_power = character->power( );
	character->AddTemporaryPowerBonus(attack_increase_);
	std::cout << name_ << "를 사용했습니다." << std::endl;
	std::cout << "공격력: " << prev_power << " -> " << character->power( ) << std::endl;
	std::cout << "============================" << std::endl;
}

int AttackBoost::price( ) const { return kPrice; }

void AttackBoost::PrintItemInfo( ) const {
	std::cout << "이름 : " << name_ << std::endl;
	std::cout << "가치 : " << kPrice << "G" << std::endl;
	std::cout << "설명 : " << "한 번의 전투 동안 공격력 " << attack_increase_ << " 만큼 증가시킨다." << std::endl;
}