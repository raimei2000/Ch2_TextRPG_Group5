#pragma once
#include <iostream>
#include <string>

class Monster;

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

public:
<<<<<<< Updated upstream
   explicit Player(const std::string& name);
=======
	Character(std::string Name, int HP, int Power, int exp);
>>>>>>> Stashed changes

    int hp() const;
    void set_hp(int new_hp);
    void set_name(const std::string& new_name);
    int power() const;
    int defence() const;

<<<<<<< Updated upstream
    void GainExp(int amount);
=======
	virtual void attack(Monster* monster) = 0;
	virtual ~Character() {};
>>>>>>> Stashed changes
};