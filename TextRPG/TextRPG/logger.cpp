#include "logger.h"

Logger::Logger( )
{
}
//Logger::~Logger()
//{
//}

Logger* Logger::instance_ = nullptr;

Logger* Logger::GetInstance( )
{
	if ( instance_ == nullptr )
	{
		instance_ = new Logger( );
	}
	return instance_;
}

void Logger::RecordMonsterKill(const std::string& monstername)
{
	monsterLogs_[ monstername ].KillMonsterCounts++;
}

void Logger::RecordMonsterDamage(const std::string& monstername, int damage)
{
	monsterLogs_[ monstername ].DamageMonsterCounts += damage;
}

void Logger::RecordCharacterDamage(int damage)
{
	characterDamageCounts_ += damage;
}

void Logger::RecordItemUse(const std::string& itemname, int itemCount)
{
	itemLogs_[ itemname ].UseItemCounts += itemCount;
}

void Logger::RecordItemGain(const std::string& itemname, int itemCount)
{
	itemLogs_[ itemname ].GainItemCounts += itemCount;
}

void Logger::RecordGoldGain(const int gold)
{
	totalGoldGained_ += gold;
}

void Logger::RecordGoldUse(const int gold)
{
	totalGoldUsed_ += gold;
}

void Logger::Log( )
{
	int num = 0;
	std::cout << std::endl;
	std::cout << "========================================\n";
	std::cout << "=============| 게임 통계 |==============\n";
	std::cout << "========================================\n\n";

	std::cout << "[ 몬스터 관련 ]\n";
	std::cout << "받은 데미지 : " << characterDamageCounts_ << std::endl << std::endl;
	num = 1;
	for ( auto monsterLog : monsterLogs_ )
	{
		std::cout << num << ". " << monsterLog.first << std::endl;
		std::cout << "  └ 처치 : " << monsterLog.second.KillMonsterCounts << std::endl;
		std::cout << "  └ 누적 데미지 : " << monsterLog.second.DamageMonsterCounts << std::endl << std::endl;
		num++;
	}
	std::cout << "_______________________________________\n\n";

	std::cout << "\n[ 아이템 관련 ]\n\n";
	num = 1;
	for ( auto itemLog : itemLogs_ )
	{
		std::cout << num << ". " << itemLog.first << std::endl;
		std::cout << "  └ 획득 갯수 : " << itemLog.second.GainItemCounts << std::endl;
		std::cout << "  └ 사용 갯수 : " << itemLog.second.UseItemCounts << std::endl << std::endl;
		num++;
	}
	std::cout << "_______________________________________\n\n";
	std::cout << "골드 관련\n\n";
	std::cout << "총 획득한 골드 : " << totalGoldGained_ << std::endl;
	std::cout << "총 사용한 골드 : " << totalGoldUsed_ << std::endl;
}