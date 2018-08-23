//Write function prototypes for the following cases.
//Use const if/when necessary.
//A function named swap() that swaps two integers.

void swap(int &intOne, int &intTwo)
{
	int temp{intOne};
	intOne = intTwo;
	intTwo = temp;
}