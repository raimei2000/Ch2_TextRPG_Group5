#include "menu.h"
#include "input_utils.h"
#include "shop.h"
#include "epilogue.h"
#include "game_utility.h"

#include <cstdlib>
#include <Windows.h>

void Menu(Character* player) {
	int choice = 0;
	bool isEndMenu = false;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while ( !isEndMenu ) {
		std::cout << std::endl << "┌──────────────────────────────────────────┐" << std::endl;
		std::cout << "│           ";
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "🎊​🎊​ 안전지대 🎊​🎊​";
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << "             │" << std::endl; 
		std::cout << "├──────────────────────────────────────────┤" << std::endl;
		std::cout << "│▶ 1. 다음 구역으로 이동 ▶ 2. 인벤토리     │" << std::endl;
		std::cout << "│▶ 3. 스탯               ▶ 4. 무인 상점    │" << std::endl;
		std::cout << "│▶ 5. 기록               ";
		SetConsoleTextAttribute(hConsole, 8);
		std::cout << "▶ 0. 게임 종료";
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << "    │" << std::endl;
		std::cout << "└──────────────────────────────────────────┘" << std::endl;
		std::cout << player->name( ) << "은(는) 무엇을 할까?" << std::endl;
		choice = InputValidator(0, 5);
		switch ( choice ) {
		case 1: {
			//battle 호출
			GameManager* game_manager = GameManager::GetInstance( );
			const bool boss_cleared = game_manager->Battle(player);

			if ( player->hp( ) <= 0 ) {
				isEndMenu = true;
			}
			else if ( boss_cleared ) {
				ShowEpilogue(player->name( ));
				isEndMenu = true;
			}
			break;
		}
		case 2: {
			//인벤토리 호출
			int choice = 0;
			bool isExitInventory = true;
			while ( true )
			{
        system("cls");
				player->DisplayInventory( );
				if ( player->inventory_size( ) == 0 ) {
					isExitInventory = false;
          game_utility::EnterToClear("[Enter를 눌러 뒤로가기]");
					break;
				}
				std::cout << "1 ~ " << player->inventory_size( ) << "를 입력하여 상세 정보\n"
					<< "0 : 나가기\n";
				choice = InputValidator(0, player->inventory_size( ));
				if ( choice == 0 ) {
					isExitInventory = false;
					break;
				}
        system("cls");
				std::cout << "\n[상세정보]\n";
				player-> PrintItemInfo(choice - 1);
			}
			break;
		}
		case 3: {
			//스탯 호출
			system("cls");
			player->Status( );
			game_utility::EnterToClear("[Enter를 눌러 뒤로가기]");
			break;
		}
		case 4: {
			//상점 호출
			Shop(player);
			break;
		}
		case 5: {
			//로그 호출
			system("cls");
			Logger* logger = Logger::GetInstance( );
			logger->Log( );
			game_utility::EnterToClear("[Enter를 눌러 뒤로가기]");
			break;
		}
		case 0: {
			//게임 종료
			isEndMenu = true;
			break;
		}
		}
	}
}

