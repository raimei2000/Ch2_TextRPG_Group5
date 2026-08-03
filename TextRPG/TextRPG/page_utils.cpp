#include "page_utils.h"

#include <cstdlib>
#include <iostream>
#include <string>

bool EnterToNextPage(const std::string& skip_target)
{
  while ( true ) {
    std::cout << std::endl;
    std::cout << "[Enter: 계속 / 0: " << skip_target << " 스킵] ";

    std::string input;
    std::getline(std::cin, input);

    if ( input.empty( ) ) {
      std::system("cls");
      return false;
    }

    if ( input == "0" ) {
      std::system("cls");
      return true;
    }

    std::cout << "Enter 또는 0을 입력해주세요." << std::endl;
  }
}