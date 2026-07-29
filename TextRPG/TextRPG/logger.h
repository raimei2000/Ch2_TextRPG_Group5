#ifndef LOGGER_H_
#define LOGGER_H_

#include<iostream>
#include<string>

class Logger
{
public:
	Logger();
	~Logger();
	void RecordMonsterKill(std::string& monstername);

	void RecordMonsterDamage(std::string& monstername, int damage);

	void RecordItemUse(std::string& itemname, int itemCount);

	void RecordItemGain(std::string& itemname, int itemCount);

	void RecordGoldGain(int gold);

	void RecordGoldUse(int gold);


	//private:

};
#endif	