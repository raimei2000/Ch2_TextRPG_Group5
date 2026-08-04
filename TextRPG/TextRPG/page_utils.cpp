#include "page_utils.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <Windows.h>

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

void EndingScroll(const std::vector<std::string>& lines) {
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.dwSize = 100;
	cursor_info.bVisible = FALSE;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &cursor_info);
	for ( const auto& line : lines ) {
		std::cout << line << std::endl;
		if ( line.empty( ) ) {
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(800));
		}
	}
}

void ShowAllAtOnce(const std::vector<std::string>& lines) {
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.dwSize = 100;
	cursor_info.bVisible = FALSE;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &cursor_info);
	for ( const auto& line : lines ) {
		std::cout << line << std::endl;
	}
}

void DelayShowAllAtOnce(const std::vector<std::string>& lines) {
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.dwSize = 100;
	cursor_info.bVisible = FALSE;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &cursor_info);
	for ( const auto& line : lines ) {
		std::cout << line << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	system("cls");
}

void ShowCursor() {
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.dwSize = 100;
	cursor_info.bVisible = TRUE;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &cursor_info);
}
