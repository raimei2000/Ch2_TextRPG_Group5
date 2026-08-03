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
	int choice;
	bool isExitShop = true;
	while ( isExitShop )
	{
		player->DisplayInventory( );
		std::cout << "0.나가기\n";
		choice = InputValidator(0, player->inventory_size( ));
		if ( choice == 0 )
		{
			isExitShop = false;
			break;
		}
		player->GainGold(player->ItemPrice(choice - 1));
		player->RemoveItem(choice - 1);
	}
}

void Shop(Character* player)
{
	int choice;
	std::cout << "1. 구매\n";
	std::cout << "2. 판매\n";
	std::cout << "0. 나가기\n";
	choice = InputValidator(0, 2);
	switch ( choice )
	{
	case 1: {
		Buy(player);
		break;
	}
	case 2: {
		Sell(player);
		break;
	}
	case 0: {
		return;
	}
	}
}
