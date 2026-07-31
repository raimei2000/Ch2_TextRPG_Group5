#include "input_utils.h"

#include <iostream>

int InputValidator(int min, int max) {
	int value_;
	while ( true ) {
		std::cin >> value_;
		if ( std::cin.fail( ) ) {
			std::cin.clear( );
			std::cin.ignore(1000, '\n');
			std::cout << "다시 입력해주세요: ";
			continue;
		}
		else if ( value_ > max || value_ < min ) {
			std::cout << "다시 입력해주세요: ";
			continue;
		}
		return value_;
	}
}