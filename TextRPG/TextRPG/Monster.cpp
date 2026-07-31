#include "monster.h"

#include <iostream>

#include "character.h"

Monster::Monster(std::string name, int health, int attack)
	: name_(name), health_(health), attack_(attack) {
}

//getter
std::string Monster::name() {
	return name_;
}
int Monster::health() {
	return health_;
}
int Monster::attack() {
	return attack_;
}

//setter
void Monster::set_name(std::string name) {
	this->name_ = name;
}
void Monster::set_health(int health) {
	this->health_ = health;
}
void Monster::set_attack(int attack) {
	this->attack_ = attack;
}


//몬스터의 체력 감소
void Monster::TakeDamage(int damage) {
	const int previous_health = health_;

	health_ -= damage;

	if ( health_ < 0 ) {
		health_ = 0;
	}
	std::cout << "[" << name_ << "] 이(가) \n"
		<< damage << "의 피해를 입었습니다.\n";
	std::cout << "HP : " << previous_health
		<< " -> " << health_ << '\n';
}
//몬스터 사망 여부 확인
bool Monster::IsDead( ) const {
	return health_ <= 0;
}
//몬스터 스텟창 확인
void Monster::PrintMonsterStatus( ) const {
	std::cout << "===== 몬스터 스텟창 =====" << '\n';
	std::cout << " 이름  : " << name_ << '\n';
	std::cout << "  HP   : " << health_ << '\n';
	std::cout << "공격력 : " << attack_ << '\n';
	std::cout << "============================\n";
}