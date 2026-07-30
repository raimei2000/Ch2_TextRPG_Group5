#pragma once

#include "monster.h"

class Goblin : public Monster {
public:

	Goblin(int player_level);

	void Attack(Character* character) override;
};