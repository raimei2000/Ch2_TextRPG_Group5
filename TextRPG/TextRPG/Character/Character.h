#pragma once
#include <iostream>
#include <string>

class Player {
protected:
    std::string name_;
    int level_;
    int max_level_;
    int hp_;
    int power_;
    int exp_;
    int max_exp_;

public:
    Player(std::string name, int hp, int power, int exp);

    int GetHP();
    void SetHP(int new_hp);
    void SetName(const std::string& new_name);
    int GetPower();
};