// recursiveBinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is the recursive version of binary search

#include "pch.h"
#include <iostream>

int binarySearch(int *array, int target, int min, int max)
{
	int middle{ (min + max) / 2 };
	if ((middle == 0) && (*(array + middle) == target))
	{
		return middle;
	}
	if ((max - min) == 1)
	{
		return -1;
	}
	if (*(array + middle) > target)
	{
		max = middle;
	}
	else if (*(array + middle) < target)
	{
		min = middle;
	}
	else
	{
		return middle;
	}
	// Using a recursive function
	binarySearch(array, target, min, max);
}

int main()
{
	//Given code
	//Given array
	int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
	// We're going to test a bunch of values to see if they produce the expected results
	const int numTestValues = 9;
	// Here are the test values
	int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	// And here are the expected results for each value
	int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };
	for (int count = 0; count < numTestValues; ++count)
	{
		// See if our test value is in the array
		int index = binarySearch(array, testValues[count], 0, 14);
		// If it matches our expected value, then great!
		if (index == expectedValues[count])
			std::cout << "test value " << testValues[count] << " passed!\n";
		else // otherwise, our binarySearch() function must be broken
			std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
	}

	//To keep the cmd open
	while (true);
	return 0;
}