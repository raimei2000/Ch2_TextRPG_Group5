#pragma once

#include <string>
#include <memory>
#include <vector>

class Item;
class Logger;

class Monster;

class Character {
private:
  int temporary_power_bonus_;

protected:
std::string name_;

int level_;
int max_level_;

int hp_;
int max_hp_;
int power_;
int defence_;

int exp_;
int max_exp_;

int gold_;
std::vector<std::unique_ptr <Item> > inventory_;

//Character가 Logger를 참조하도록 변수 추가
Logger* logger_;

void ApplyDeveloperMode( );

void LevelUp();

public:
//Character 생성자에서 Logger 받기
explicit Character(const std::string& name, Logger* logger);
~Character( );

const std::string& name() const;
int level() const;
int hp() const;
int max_hp() const;
int power() const;
int defence() const;
int exp() const;
int max_exp() const;

void set_power(int new_power);
void set_hp(int new_hp);
void set_name(const std::string& new_name);

//공격력 up 포션을 사용했을 때 해당 전투에서만 공격력 업
void AddTemporaryPowerBonus(int amount);
void ClearTemporaryPowerBonus( );

void GainExp(int amount);

void Status( )const;

void TakeDamage(int damage);
void Attack(Monster* damage);
//골드
int gold( ) const;
void GainGold(int amount);
bool UseGold(int amount);

int inventory_size( ) const;
void AddItem(std::unique_ptr<Item> item);
void UseItem(int index);
void DisplayInventory( ) const;
void PrintItemInfo(int index) const;

//아이템 이름 확인
std::string ItemName(int index) const;

//아이템 가격 확인
int ItemPrice(int i) const;

//아이템 제거
void RemoveItem(int i);
};