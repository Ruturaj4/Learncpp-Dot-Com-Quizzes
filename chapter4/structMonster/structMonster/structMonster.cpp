// structMonster.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

enum class MonsterType
{
	OGRE,
	DRAGON,
	ORC,
	GIANTSPIDER,
	SLIME,
};

struct Monster
{
	std::string monsterName;
	int monsterHealth;
	MonsterType type;
};

std::string getMonsterType (Monster mon)
{
	if (mon.type == MonsterType::DRAGON)
		return "Dragon";
	else if (mon.type == MonsterType::OGRE)
		return "Ogre";
	else if (mon.type == MonsterType::ORC)
		return "Orc";
	else if (mon.type == MonsterType::GIANTSPIDER)
		return "Giant Spider";
	else if (mon.type == MonsterType::SLIME)
		return "Slime";
}

void printMonster(Monster mon)
{
	std::cout << "This " << getMonsterType(mon) << " is named " <<
		mon.monsterName << " and has " << mon.monsterHealth << " health." << "\n";
}

int main()
{
	Monster ogre{ "Torg", 145, MonsterType::OGRE };
	Monster slime{ "Blurp", 23, MonsterType::SLIME };
	printMonster(ogre);
	printMonster(slime);
	//To keep cmd open
	int x;
	std::cin >> x;
    return 0;
}

