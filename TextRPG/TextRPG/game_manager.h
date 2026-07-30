#pragma once

class Character;
class Monster;

class GameManager {
public:
  Monster* GenerateMonster(int player_level);
  void Battle(Character* player);
  void DisplayInventory(Character* player);
  
  // For singleton.
  // delete copy, assignment operator.
  GameManager(const GameManager&) = delete;
  GameManager& operator=(const GameManager&) = delete;
  // static method. return unique GameManager instance. 
  static GameManager* GetInstance();
  // For singleton.

private:
  static GameManager* instance; // static pointer to unique GameManager instance

  GameManager();
};