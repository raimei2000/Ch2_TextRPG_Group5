#include "logger.h"

//Logger::Logger()
//{
//}
//Logger::~Logger()
//{
//}

void Logger::RecordMonsterKill(const std::string& monstername)
{
	monsterLogs_[monstername].KillMonsterCounts++;
}

void Logger::RecordMonsterDamage(const std::string& monstername, int damage)
{
	monsterLogs_[monstername].DamageMonsterCounts += damage;
}

void Logger::RecordItemUse(const std::string& itemname, int itemCount)
{
	itemLogs_[itemname].UseItemCounts += itemCount;
}

void Logger::RecordItemGain(const std::string& itemname, int itemCount)
{
	itemLogs_[itemname].GainItemCounts += itemCount;
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
	for ( auto monsterLog : monsterLogs_ )
	{
		std::cout << "잡은 " << monsterLog.first << "의 마리 수 : " << monsterLog.second.KillMonsterCounts;
		std::cout << " / 누적 데미지 : " << monsterLog.second.DamageMonsterCounts << std::endl;
	}
	for ( auto itemLog : itemLogs_ )
	{
		std::cout << "얻은 " << itemLog.first << "의 개수 : " << itemLog.second.GainItemCounts;
		std::cout << " / 사용한 아이템의 개수 : " << itemLog.second.UseItemCounts << std::endl;
	}
	if ( totalGoldGained_ != 0 )
	{
		std::cout << "총 획득한 골드 : " << totalGoldGained_ << std::endl;
		std::cout << "총 사용한 골드 : " << totalGoldUsed_ << std::endl;
	}
}