// MonsterGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Monster
{
public:
	enum class MonsterType
	{
		DRAGON, GOBLIN, OGRE, ORC, SKELETON, TROLL, VAMPIRE, ZOMBIE, MAX_MONSTER_TYPES,
	};
	Monster(MonsterType type, std::string name, std::string roar, int hitPoints )
		: m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints)
	{

	}
	std::string getTypeString(MonsterType type)
	{
		switch (type)
		{
		case MonsterType::DRAGON:
			return "Dragon";
		case MonsterType::GOBLIN:
			return "Goblin";
		case MonsterType::OGRE:
			return "Ogre";
		case MonsterType::ORC:
			return "Orc";
		case MonsterType::SKELETON:
			return "Skeleton";
		case MonsterType::TROLL:
			return "Troll";
		case MonsterType::VAMPIRE:
			return "Vampire";
		case MonsterType::ZOMBIE:
			return "Zombie";
		default:
			return "???";
		}
	}
	void print()
	{
		std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hitPoints <<
			" hit points and says " << m_roar << '\n';
	}
private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hitPoints;
};

class MonsterGenerator
{
public:
	static int randomNumberGererator(int min, int max)
	{
		static const double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
		return static_cast<int> (rand() * fraction * (max - min + 1) + min);
	}
	static Monster generateMonster()
	{
		Monster::MonsterType randomType
			= static_cast<Monster::MonsterType>(randomNumberGererator(0, static_cast<int>(Monster::MonsterType::MAX_MONSTER_TYPES) - 1));
		int randomhitPoint = randomNumberGererator(1, 100);
		static std::string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
		static std::string s_roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };

		return Monster(randomType, s_names[randomNumberGererator(0, 5)], s_roars[randomNumberGererator(0, 5)], randomhitPoint);
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0))); //Seed value
	rand();

	Monster skele(Monster::MonsterType::SKELETON, "Bones", "*rattle*", 4);
	skele.print();

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	//To keep the cmd open
	while (true);
	return 0;
}