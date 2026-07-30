#pragma once

#include <string>

class Character {
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

void LevelUp();

public:
explicit Character(const std::string& name);

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

void GainExp(int amount);

void status( )const;
};