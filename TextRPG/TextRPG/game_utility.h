#pragma once

#include <iostream>

namespace game_utility {
  // time초 동안 대기
  void Delay(unsigned int time);

  // time초 후에 자동으로 안전지대로 이동
  void AutoReturnToSafeZone(unsigned int time);

  // message를 출력하고 Enter입력 받으면 화면 초기화
  void EnterToClear(const std::string& message);
}