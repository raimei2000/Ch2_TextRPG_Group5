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
	health_ -= damage;

	if ( health_ < 0 ) {
		health_ = 0;
	}
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
	std::cout << "============================" << '\n';
}
//몬스터 출현 문구
void Monster::PrintSpawnMessage( ) const {
	if ( name_ == "고블린" ) {
		std::cout << "============================\n";
		std::cout << "🤢 야생에서 악취 고블린이 나타났다!\n";
		std::cout << "< 강력한 악취가 주변을 뒤덮는다... >\n";
		std::cout << "============================\n";
	}
	else if ( name_ == "오크" ) {
		std::cout << "============================\n";
		std::cout << "🍺 술취한 오크가 비틀거리며 나타났다!\n";
		std::cout << "	< 술 냄새가 진동한다... >\n";
		std::cout << "============================\n";
	}
	else if ( name_ == "트롤" ) {
		std::cout << "============================\n";
		std::cout << "💪 헬창 트롤이 등장했다!\n";
		std::cout << "< 오늘도 단백질 300g 먹었다...헤헤>\n";
		std::cout << "============================\n";
	}
}