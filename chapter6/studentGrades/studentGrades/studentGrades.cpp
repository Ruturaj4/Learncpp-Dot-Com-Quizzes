// studentGrades.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

struct StudentInfo
{
	std::string studentName;
	int grade;
};

void sortedList(StudentInfo *array, int numberOfStudents)
{
	for (int index = 0; index < numberOfStudents; index++)
	{
		for (int innerIndex = 0; innerIndex < numberOfStudents - index - 1; ++innerIndex)
		{
			if ((array + innerIndex)->grade < (array + innerIndex + 1)->grade)
			{
				std::swap(*(array + innerIndex), *(array + innerIndex + 1));
			}
		}
	}
}

int main()
{
	std::cout << "How many students you want to enter?\n";
	int numberOfStudents{ 0 };
	std::cin >> numberOfStudents;
	StudentInfo *array = new StudentInfo[numberOfStudents];
	std::cout << "Now enter student names and grade(in the range of 0 to 100).\n";
	for (int index = 0; index < numberOfStudents; ++index)
	{
		std::cout << "Please enter name " << index + 1 << ": ";
		std::cin >> (array + index)->studentName;
		do
		{
			std::cout << "Grade " << index + 1 << ": ";
			std::cin >> (array + index)->grade;
		} while (((array + index)->grade >= 100)||((array + index)->grade < 0));
	}
	sortedList(array, numberOfStudents);
	std::cout << "\n";
	for (int index = 0; index < numberOfStudents; index++)
	{
		std::cout << (array + index)->studentName << " got a grade of " << (array + index)->grade << "\n";
	}
	//Almost forgot to deallocate the memory!
	delete[] array;
	//To keep the cmd open
	while (true);
    return 0;
}