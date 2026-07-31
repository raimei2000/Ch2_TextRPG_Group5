#include "shop.h"

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
		auto pHealthPotion = std::move(std::make_unique<HealthPotion>( ));
		auto pAttackBoost = std::move(std::make_unique<AttackBoost>( ));
		//아이템 가치를 넣어놓은 변수가 있나요? (임의로 모두 30으로)
		std::cout << "상점 목록\n";
		std::cout << "1. 체력 포션 (" << pHealthPotion->price( ) << "G)";
		std::cout << "2. 공격력 부스트 (" << pAttackBoost->price( ) << "G)";
		std::cout << "0. 나가기\n";
		std::cout << "보유 골드 : " << player->gold( ) << std::endl;
		choice_ = InputValidator(0, 2);
		switch ( choice_ )
		{
		case 1: {
			if ( pHealthPotion->price( ) <= player->gold( ) )
			{
				player->UseGold(30);
				player->AddItem(std::move(pHealthPotion));

			}
			else
			{
				std::cout << "gold가 부족합니다\n";
			}
			break;
		}
		case 2: {
			if ( pAttackBoost->price( ) <= player->gold( ) )
			{
				player->UseGold(30);
				player->AddItem(std::move(pAttackBoost));
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
		choice = InputValidator(0, player->inventory_size( ) + 1);
		if ( choice == 0 )
		{
			isExitShop = false;
			break;
		}
		player->GainGold((30 / 3) * 2);
		//플레이어 아이템 삭제 함수 있나요?
		break;
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
