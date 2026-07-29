#include "random_number_generator.h"

#include <random>

// 랜덤으로 [start, end] 범위의 정수를 반환
int RandomNumberGenerator::RandomInteger(int start, int end) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(start, end);

  return distrib(gen);
}