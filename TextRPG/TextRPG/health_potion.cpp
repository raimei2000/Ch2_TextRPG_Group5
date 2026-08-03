#include "health_potion.h"

#include <iostream>

#include "character.h"

HealthPotion::HealthPotion( ) : Item("HP포션"), health_restore_(50) {}

void HealthPotion::Use(Character* character) {
	int prev_hp = character->hp( );
	character->set_hp(character->hp() + health_restore_);
	std::cout << name_ << "을 사용했습니다." << std::endl;
	std::cout << "HP: " << prev_hp << "->" << character->hp( ) << std::endl;
	std::cout << "============================" << std::endl;
}

int HealthPotion::price( ) const { return kPrice; }

void HealthPotion::PrintItemInfo( ) const{
	std::cout << "이름 : " << name_ << std::endl;
	std::cout << "가치 : " << kPrice << std::endl;
	std::cout << "설명 : " << "체력을 " << health_restore_ << " 만큼 회복 시켜준다." << std::endl;
}
