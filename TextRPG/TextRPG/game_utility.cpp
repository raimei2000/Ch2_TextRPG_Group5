#include "game_utility.h"

#include <chrono>
#include <iostream>
#include <limits>
#include <thread>

void game_utility::Delay(unsigned int time) {
  std::this_thread::sleep_for(std::chrono::seconds(time));
}

void game_utility::AutoReturnToSafeZone(unsigned int time) {
  std::cout << std::endl;
  std::cout << "안전지대로 돌아가자.." << std::endl;
  for ( int i = time; i > 0; i-- ) {
    std::cout << "\r" << i << "초 후 안전지대로 이동" << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  system("cls");
}

void game_utility::EnterToClear(const std::string& message) {
  std::cout << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max( ), '\n');  // 남은 입력 비우기
  std::cout << message;
  std::cin.get();

  std::system("cls");
}