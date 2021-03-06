// switchAnimalLegs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

enum class Animal
{
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH,
};

std::string getAnimalName(Animal animal)
{
	switch (animal)
	{
	case Animal::PIG:
		return "Pig";
	case Animal::CHICKEN:
		return "Chicken";
	case Animal::GOAT:
		return "Goat";
	case Animal::CAT:
		return "Cat";
	case Animal::DOG:
		return "Dog";
	case Animal::OSTRICH:
		return "Ostrich";
	default:
		std::cout << "????";
	}
}

void printNumberOfLegs(Animal animal)
{
	switch (animal)
	{
	case Animal::PIG:
	case Animal::GOAT:
	case Animal::CAT:
	case Animal::DOG:
		std::cout << "The animal " << getAnimalName(animal) << " has 4 legs." << std::endl;
		break;
	case Animal::CHICKEN:
	case Animal::OSTRICH:
		std::cout << "The animal " << getAnimalName(animal) << " has 2 legs." << std::endl;
		break;
	default:
		std::cout << "???" << std::endl;
	}
}

int main()
{
	printNumberOfLegs(Animal::CAT);
	printNumberOfLegs(Animal::CHICKEN);
	//To keep cmd open
	int x;
	std::cin >> x;
    return 0;
}