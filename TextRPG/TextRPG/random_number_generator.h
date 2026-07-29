#pragma once

class RandomNumberGenerator {
public:
  // 랜덤으로 [start, end] 범위의 정수를 반환
  // RandomNumberGenerator::RandomInteger(3, 5) => 3, 4, 5 중 하나를 랜덤으로 반환
  static int RandomInteger(int start, int end);
};