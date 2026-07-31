#pragma once

#include "monster.h"

class BossOgre : public Monster {
private:
  bool is_angry_ = false;

public:
  BossOgre( );

  void Attack(Character* character) override;
  void SpawnMessage( ) const override;
  void DeathMessage( ) const override;
};