#ifndef LOGGER_H_
#define LOGGER_H_

#include<iostream>
#include<string>
#include<map>

struct MonsterLog
{
	int KillMonsterCounts = 0;
	int DamageMonsterCounts = 0;
};
struct IteamLog
{
	int UseItemCounts = 0;
	int GainItemCounts = 0;
};

class Logger
{
private:
	std::map<std::string, MonsterLog>monsterLogs;
	std::map<std::string, IteamLog>ItemLogs;
	int totalGoldGained = 0;
	int totalGoldUsed = 0;

public:
	Logger();
	// ~Logger();
	void RecordMonsterKill(const std::string& monstername);

	void RecordMonsterDamage(const std::string& monstername, int damage);

	void RecordItemUse(const std::string& itemname, int itemCount);	

	void RecordItemGain(const std::string& itemname, int itemCount);

	void RecordGoldGain(const int gold);

	void RecordGoldUse(const int gold);

	void Log();

};
#endif	