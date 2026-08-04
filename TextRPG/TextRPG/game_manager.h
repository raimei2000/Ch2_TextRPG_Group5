#pragma once

class Monster;
class Character;

class GameManager {
public:
  // 플레이어 레벨 기반 랜덤한 종류의 몬스터 생성
  Monster* RandomSpawnMonster(int player_level);
  // 전투 진입
  void Battle(Character* player);
  bool boss_cleared( ) { return boss_cleared_; }
  
  // For singleton.
  // delete copy, assignment operator.
  GameManager(const GameManager&) = delete;
  GameManager& operator=(const GameManager&) = delete;
  // static method. return unique GameManager instance. 
  static GameManager* GetInstance();
  // For singleton.

private:
  static GameManager* instance_; // static pointer to unique GameManager instance
  static bool boss_cleared_;

  GameManager() = default;
};