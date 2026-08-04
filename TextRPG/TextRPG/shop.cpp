#include "shop.h"

#include <cstdlib>
#include <memory>

#include "health_potion.h"
#include "attack_boost.h"
#include "game_utility.h"

//void Shop( ) {
//	std::cout << R"(
// /\ /\ /\ /\ /\ /\ /\
//+---------------------+
//|   *** 공 사 중 ***  |
//|    (╯°□°)╯︵ ┻━┻    |
//+---------------------+
//|#####|####|####|#####|
//   ||             ||
//===++=============++===


void Buy(Character* player)
{
	int choice_;
	bool isExitShop = true;
	while ( isExitShop )
	{
		std::cout << "┌────────────────────────────────────────┐" << std::endl;
		std::cout << "│             탕비실 자판기              │" << std::endl;
		std::cout << "├────────────────────────────────────────┤" << std::endl;
		std::cout << "│       " << "1. 체력 포션 (" << HealthPotion::kPrice * 3 << "G)" << "               │" << std::endl;
		std::cout << "│       " << "2. 공격력 부스트(" << AttackBoost::kPrice * 3 << "G)" << "           │" << std::endl;
		std::cout << "│       0. 자판기 나가기                 │" << std::endl;
		std::cout << "└────────────────────────────────────────┘" << std::endl;
		std::cout << "보유 골드 : " << player->gold( ) << "G" << std::endl;
		choice_ = InputValidator(0, 2);
		switch ( choice_ )
		{
		case 1: {
			system("cls");
			int price = HealthPotion::kPrice * 3;
			if ( price <= player->gold( ) )
			{
				player->UseGold(price);
				player->AddItem(std::make_unique<HealthPotion>());
				std::cout << std::endl;
			}
			else
			{
				system("cls");
				std::cout << "[골드가 부족합니다]\n\n";
			}
			break;
		}
		case 2: {
			system("cls");
			int price = AttackBoost::kPrice * 3;
			if ( price <= player->gold( ) )
			{
				player->UseGold(price);
				player->AddItem(std::make_unique<AttackBoost>());
				std::cout << std::endl;
			}
			else
			{
				system("cls");
				std::cout << "[골드가 부족합니다]\n\n";
			}
			break;
		}
		case 0: {
			isExitShop = false;
			//std::cout << "상점을 나갑니다.\n";
			break;
		}
		}
	}
}

void Sell(Character* player)
{
	bool isExitShop = true;
	while ( isExitShop )
	{
		std::cout << "┌────────────────────────────────────────┐" << std::endl;
		std::cout << "│             보급품 회수소              │" << std::endl;
		std::cout << "└────────────────────────────────────────┘" << std::endl;
		// 인벤토리가 비었다면
		if ( player->inventory_size( ) == 0 ) {
			std::cout << "반납할 물품이 없습니다." << std::endl;
			std::cout << "=======================" << std::endl;
			game_utility::EnterToClear("[Enter를 눌러 뒤로가기]");
			return;
		}
		// 판매할 아이템이 있다면 아이템 이름, 판매가격 출력
		for ( int i = 0; i < player->inventory_size( ); ++i ) {
			const int sell_price = player->ItemPrice(i);
			std::cout << i + 1 << ". " << player->ItemName(i) << " (환급가격: " << sell_price << " G)" << std::endl;
		}
			std::cout << "0. 회수 처리 종료" << std::endl;
			std::cout << "보유 골드 : " << player->gold( ) << "G" << std::endl;
			std::cout << "반납할 아이템을 선택해주세요:" << std::endl;

			const int choice = InputValidator(0, player->inventory_size( ));

			if ( choice == 0 ) {
				isExitShop = false;
				std::cout << "회수를 종료합니다." << std::endl;
				continue;
			}
			//화면 번호 실제 인덱스로 변환
			const int item_index = choice - 1;

			//아이템 제거 전 정보 저장
			const std::string item_name = player->ItemName(item_index);
			const int sell_price = player->ItemPrice(item_index);

			//판매 골드 지급 후 아이템 제거
			player->GainGold(sell_price);
			player->RemoveItem(item_index);

			//판매완료 문구
			system("cls");
			std::cout << item_name << " 아이템을 판매하였습니다." << std::endl;
			std::cout << sell_price << " G를 획득하였습니다." << std::endl;
			std::cout << "현재 골드: " << player->gold( ) << "G" << std::endl << std::endl;
	}
}

void Shop(Character* player)
{
	while ( true ) {
		system("cls");
		std::cout << "┌────────────────────────────────────────┐" << std::endl;
		std::cout << "│       제13 던전 안전구역 탕비실        │" << std::endl;
		std::cout << "├────────────────────────────────────────┤" << std::endl;
		std::cout << "│            1. 자판기                   │" << std::endl;
		std::cout << "│            2. 보급품 회수소(판매)      │" << std::endl;
		std::cout << "│            0. 탕비실 나가기            │" << std::endl;
		std::cout << "└────────────────────────────────────────┘" << std::endl;

		const int choice = InputValidator(0, 2);

		switch ( choice ) {
		case 1: {
			system("cls");
			Buy(player);
			break;
		}
		case 2: {
			system("cls");
			Sell(player);
			break;
		}
		case 0: {
			//std::cout << "상점을 나갑니다." << std::endl;
			system("cls");
			return;
		}
		}
	}
}
