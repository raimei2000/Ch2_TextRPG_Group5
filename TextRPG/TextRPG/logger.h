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
	static Logger* instance;
	std::map<std::string, MonsterLog>monsterLogs_;
	std::map<std::string, IteamLog>itemLogs_;
	int totalGoldGained_ = 0;
	int totalGoldUsed_ = 0;

	Logger( );
	Logger(const Logger&);
	Logger& operator = (const Logger&);

public:
	//~Logger();

	//Logger 객체 포인터 반환
	static Logger* getInstance( );

	//몬스터 킬 카운터
	void RecordMonsterKill(const std::string& monstername);
	//몬스터 누적 데미지
	void RecordMonsterDamage(const std::string& monstername, int damage);
	//총 사용 아이템
	void RecordItemUse(const std::string& itemname, int itemCount = 1);
	//총 획득 아이템
	void RecordItemGain(const std::string& itemname, int itemCount = 1);
	//총 사용 골드
	void RecordGoldUse(const int gold);
	//총 획득 골드
	void RecordGoldGain(const int gold);
	//모든 로그 출력
	void Log( );

};
#endif