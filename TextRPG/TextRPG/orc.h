#pragma once

#include "monster.h"

class Orc : public Monster {
public:

	Orc(int player_level);

	void Attack(Character* character) override;
	void SpawnMessage( ) const override;
	void DesthMessage( ) const override;
};