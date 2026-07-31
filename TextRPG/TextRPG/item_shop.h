#pragma once

#include <iostream>
#include <string>

#include "character.h"
#include "input_utils.h"



void Shop_In(Character* character)
{
	std::cout << "판매 목록";
	std::cout << "1. 체력 포션\n";
	std::cout << "2. 체력 부스터\n";
		

	std::cout << "보유 골드 : " << character->gold( );
	int choice_;
	choice_ = InputValidator(1, 2);
	switch ( choice_ )
	{
	case 1: {
