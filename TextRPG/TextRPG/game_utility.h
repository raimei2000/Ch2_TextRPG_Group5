#pragma once

namespace game_utility {
  // time초 동안 대기
  void Delay(int time);

  // time초 후에 자동으로 안전지대로 이동
  void AutoReturnToSafeZone(int time);
}