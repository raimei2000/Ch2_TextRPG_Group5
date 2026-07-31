#pragma once

#include "monster.h"

class Troll : public Monster {
public:

	Troll(int player_level);

	void Attack(Character* character) override;
	void SpawnMessage( ) const override;
	void DesthMessage( ) const override;
};