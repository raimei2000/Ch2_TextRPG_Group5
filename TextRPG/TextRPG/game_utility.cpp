#include "game_utility.h"

#include <chrono>
#include <iostream>
#include <thread>

void game_utility::Delay(int time) {
  std::this_thread::sleep_for(std::chrono::seconds(time));
}

void game_utility::AutoReturnToSafeZone(int time) {
  std::cout << std::endl;
  std::cout << "안전지대로 돌아가자.." << std::endl;
  for ( int i = time; i > 0; i-- ) {
    std::cout << "\r" << i << "초 후 안전지대로 이동" << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  system("cls");
}