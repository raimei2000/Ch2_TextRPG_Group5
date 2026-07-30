#include "character.h"
#include "monster.h"
#include "item.h"
#include "logger.h"

#include <iostream>
#include <utility>

Character::~Character( ) = default;

//생성자 Logger 연결
Character::Character(const std::string& name, Logger* logger)
: name_(name),
level_(1),
max_level_(10),
hp_(200),
max_hp_(200),
power_(30),
defence_(30),
exp_(0),
max_exp_(100),
gold_(0),
logger_(logger) {

}

const std::string& Character::name() const {
return name_;
}

int Character::level() const {
return level_;
}

int Character::hp() const {
return hp_;
}

int Character::max_hp() const {
return max_hp_;
}

int Character::power() const {
return power_;
}

int Character::defence() const {
return defence_;
}

int Character::exp() const {
return exp_;
}

int Character::max_exp() const {
return max_exp_;
}

//골드함수
int Character::gold( ) const {
return gold_;
}

void Character::GainGold(int amount) {
if ( amount <= 0 ) {
return;
}
//현재 보유골드 갱신
gold_ += amount;

//총 획득골드 기록
if ( logger_ != nullptr ) {
logger_->RecordGoldGain(amount);
}
}


bool Character::UseGold(int amount) {
if ( amount <= 0 || amount > gold_ ) {
  return false;
}
gold_ -= amount;

//총 사용골드 기록
if ( logger_ != nullptr ) {
  logger_->RecordGoldUse(amount);
}
  return true;
}

void Character::set_hp(int new_hp) {
if (new_hp < 0) {
hp_ = 0;
}
else if (new_hp > max_hp_) {
hp_ = max_hp_;
}
else {
hp_ = new_hp;
}
}

void Character::set_power(int new_power) {
if (new_power < 0){
power_ = 0;
}
else {
power_ = new_power;
}
}

void Character::set_name(const std::string& new_name) {
name_ = new_name;
}


void Character::status() const {

//캐릭터 스테이터스 표시
std::cout << "===== Character Status =====" << std::endl;
std::cout << "Name    : " << name_ << std::endl;
std::cout << "Lovel   : " << level_ << "/" << max_level_ << std::endl;
std::cout << "HP      : " << hp_ << "/" << max_hp_ << std::endl;
std::cout << "Power   : " << power_ <<std::endl;
std::cout << "Defernce: " << defence_ <<std::endl;
std::cout << "Exp     : " << exp_ << "/" << max_exp_ << std::endl;
std::cout << "Gold    : " << gold_ << " G"<< std::endl;
std::cout << "============================" << std::endl;
}

//캐릭터가 데미지를 받을 경우
void Character::TakeDamage(int damage) {
std::cout << "============================" << std::endl;
std::cout << "[" << name_ << "] 이(가) 데미지를 입었습니다." << std::endl;
std::cout << "HP : " << hp_ << " -> HP : " << hp_ - damage << std::endl;
std::cout << "============================" << std::endl;

set_hp(hp_ - damage);
}

//캐릭터가 공격을 할 경우
void Character::Attack(Monster* damage) {
std::cout << "============================" << std::endl;
std::cout << "[" << name_ << "] 이(가)" << damage->name( ) << "에게 " << std::endl << power_ << "의 피해를 입혔습니다." << std::endl;
std::cout << "============================" << std::endl;

damage->TakeDamage(power_);
}

//아이템 추가
void Character::AddItem(std::unique_ptr<Item> item) {
if ( item == nullptr ) { //전달받은 아이템 없으면 종료
return;
}
//uniqe_ptr 이동 전에 아이템 이름 저장
const std::string item_name = item->name( );

//logger 연결돼있으면 아이템 획득 기록
inventory_.push_back(std::move(item));
if ( logger_ != nullptr ) {
logger_->RecordItemGain(item_name);
}

std::cout << item_name << " 아이템을 획득했습니다." << std::endl;
}

//인벤토리 크기 확인
int Character::inventory_size( ) const {
return static_cast<int> (inventory_.size( ));
}

//아이템 사용
void Character::UseItem(int index) {
if ( index < 0 || index >= inventory_size( ) ) {
return;
}
inventory_[ index ]->Use(this);

//사용한 아이템 제거
inventory_.erase(inventory_.begin( ) + index);
}

//인벤토리 표시
void Character::DisplayInventory( ) const {
std::cout << "========인벤토리========" << std::endl;
if ( inventory_.empty( ) ) {
std::cout << "인벤토리가 비어있습니다." << std::endl;
}
else {
for ( int i = 0; i < inventory_size( ); i++ ) {
std::cout << i << ". " << inventory_[ i ]->name( ) << std::endl;
}
}
std::cout << "========================" << std::endl;
}
