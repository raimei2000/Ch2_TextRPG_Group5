#pragma once

#include <string>

//전방 선언
class Character;

class Monster {

protected:
	std::string name_;
	int health_;
	int attack_;


public:
	//순수 가상 함수
	Monster(std::string name, int health, int attack);

	virtual void Attack(Character* character) = 0;

	//getter
	std::string name();
	int health();
	int attack();

	//setter
	void set_name(std::string name);
	void set_health(int health);
	void set_attack(int attack);

	//몬스터의 체력 감소
	void TakeDamage(int damage);
	//몬스터 사망 여부 확인
	bool IsDead( ) const;
	//몬스터 스텟창
	void PrintMonsterStatus( ) const;
	//몬스터 출현 문구
	void PrintSpawnMessage( ) const ;

};


