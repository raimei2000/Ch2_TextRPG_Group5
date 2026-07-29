#pragma once

class Character;
class Monster;

class GameManager {
public:
  Monster* GenerateMonster(int player_level);
  void Battle(Character* player);
  void DisplayInventory(Character* player);

private:

};