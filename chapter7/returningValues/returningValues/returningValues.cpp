// returningValues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <tuple>

//sumTo() takes the integer paramenter and returns sum of all the numbers between 1 and input number
int sumTo(const int useInt)
{
	int sum{ 0 };
	for (int index = 2; index < useInt; index++)
	{
		sum += index;
	}
	return sum;
}

//Structure employee
struct Employee
{
	int employeeID;
	std::string employeeName;
};

//printEmployeeName() takes an employee struct as input
void printEmployeeName(const Employee &employee)
{
	std::cout << "Employee name: " << employee.employeeName << "\n";
	std::cout << "Employee ID: " << employee.employeeID << "\n";
}

//minmax() takes two integers as an imput and passes back to the caller, the smaller and larger number as separate paramenters
void minmax(const int intOne, const int intTwo, int &minOut, int &maxOut)
{
	if (intOne < intTwo)
	{
		minOut = intOne;
		maxOut = intTwo;
	}
	else
	{
		minOut = intTwo;
		maxOut = intOne;
	}
}

//getIndexOfLargestValue() takes an integer array (as a pointer) and an array size, and returns
//the index of the largest element in the array
int getIndexOfLargestValue(const int *array,const int arraySize)
{
	int temp{ 0 };
	int largerElementIndex{ 0 };
	for (int index = 0; index < arraySize; index++)
	{
		if (array[index] > array[largerElementIndex])
		{
			largerElementIndex = index;
		}
	}
	return largerElementIndex;
}

//getElement() takes an integer array (as a pointer) and an index and returns the array
//element at that index (not a copy). Assume the index is valid, and the return value is const
//Passing by reference
const int& getElement(const int *array, const int arrayIndex)
{
	return array[arrayIndex];
}

int main()
{
	//1st quiz
	std::cout << "This function takes an integer and returns sum of all the numbers between 1 and " <<
		"imput number\n";
	std::cout << "Enter an integer: ";
	int userInt{ 0 };
	std::cin >> userInt;
	std::cout << "Sum: " << sumTo(userInt) << "\n";

	//2nd quiz
	Employee employee;
	employee.employeeName = "Ruturaj";
	employee.employeeID = 23;
	printEmployeeName(employee);

	//3rd quiz
	int minOut{ 4 };
	int maxOut{ 2 };
	minmax(4, 2, minOut, maxOut);
	std::cout << "The Smaller number is: " << minOut << "\n";
	std::cout << "The larger number is: " << maxOut << "\n";

	//4th quiz
	const int arraySize{ 4 };
	int array[arraySize]{ 44,88,444,22 };
	std::cout << "Index of the Largest element: " << getIndexOfLargestValue(array, arraySize) << "\n";

	//5th quiz
	int arrayIndex{ 2 };
	int elementAtIndex{ getElement(array, arrayIndex) };
	std::cout << "Element at the specified index: " << elementAtIndex << "\n";

	//To keep the cmd open
	while (true);
    return 0;
}