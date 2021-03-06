// binarySearch.cpp : Defines the entry point for the console application.
// This is the iterative version of binary search


#include "stdafx.h"
#include <iostream>

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(int *array, int target, int min, int max)
{
	int middle{ (min + max) / 2 };
	while (middle > 0)
	{
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
		middle = (min + max) / 2;
		//For the first element in an array
		if ((middle == 0) && (*(array + middle) == target))
		{
			return middle;
		}
		//To avoid infinite looping
		if ((max - min) == 1)
		{
			break;
		}
	}
	return -1;
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