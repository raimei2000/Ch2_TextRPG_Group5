#pragma once
#include <iostream>
#include <string>

class Player {
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

public:
    Player(std::string name, int hp, int power, int defence, int exp);

    int hp() const;
    void set_hp(int new_hp);
    void set_name(const std::string& new_name);
    int power() const;
    int defence() const;
    void GainExp(int amount);
};