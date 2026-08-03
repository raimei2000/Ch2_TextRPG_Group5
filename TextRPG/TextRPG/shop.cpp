#include "shop.h"

#include <memory>

#include "health_potion.h"
#include "attack_boost.h"

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
		std::cout << "상점 목록\n";
		std::cout << "1. 체력 포션 (" << HealthPotion::kPrice * 3 << "G)\n";
		std::cout << "2. 공격력 부스트 (" << AttackBoost::kPrice * 3 << "G)\n";
		std::cout << "0. 나가기\n";
		std::cout << "보유 골드 : " << player->gold( ) << std::endl;
		choice_ = InputValidator(0, 2);
		switch ( choice_ )
		{
		case 1: {
			int price = HealthPotion::kPrice * 3;
			if ( price <= player->gold( ) )
			{
				player->UseGold(price);
				player->AddItem(std::make_unique<HealthPotion>());

			}
			else
			{
				std::cout << "gold가 부족합니다\n";
			}
			break;
		}
		case 2: {
			int price = AttackBoost::kPrice * 3;
			if ( price <= player->gold( ) )
			{
				player->UseGold(price);
				player->AddItem(std::make_unique<AttackBoost>());
			}
			else
			{
				std::cout << "gold가 부족합니다\n";
			}
			break;
		}
		case 0: {
			isExitShop = false;
			std::cout << "상점을 나갑니다.\n";
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
		std::cout <<std::endl<< "======아이템 판매======" << std::endl;
		if ( player->inventory_size( ) == 0 ) {
			std::cout << "판매할 아이템이 없습니다." << std::endl;
			std::cout << "=======================" << std::endl;
			return;
		}
		//아이템 이름, 판매가격 출력
		for ( int i = 0; i < player->inventory_size( ); ++i ) {
			const int sell_price = player->ItemPrice(i);
			std::cout << i + 1 << ". " << player->ItemName(i) << " (판매가격: " << sell_price << " G)" << std::endl;
		}
			std::cout << "0. 판매 종료" << std::endl;
			std::cout << "보유 골드 : " << player->gold( ) << "G" << std::endl;
			std::cout << "판매할 아이템을 선택해주세요:" << std::endl;

			const int choice = InputValidator(0, player->inventory_size( ));

			if ( choice == 0 ) {
				isExitShop = false;
				std::cout << "판매를 종료합니다." << std::endl;
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
			std::cout << item_name << " 아이템을 판매하였습니다." << std::endl;
			std::cout << sell_price << " G를 획득하였습니다." << std::endl;
			std::cout << "현재 골드: " << player->gold( ) << "G" << std::endl;
	}
}

void Shop(Character* player)
{
	while ( true ) {
		std::cout << "====== 상점 ======" << std::endl;
		std::cout << "1. 구매" << std::endl;
		std::cout << "2. 판매" << std::endl;
		std::cout << "0. 상점 나가기" << std::endl;
		std::cout << "===================" << std::endl;

		const int choice = InputValidator(0, 2);

		switch ( choice ) {
		case 1: {
			Buy(player);
			break;
		}
		case 2: {
			Sell(player);
			break;
		}
		case 0: {
			std::cout << "상점을 나갑니다." << std::endl;
			return;
		}
		}
	}
}
