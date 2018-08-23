//Write function prototypes for the following cases.
//Use const if/when necessary.
//A function named getLargestElement() that takes a dynamically allocated
//array of integers and returns the largest number in such a
//way that the caller can change the value of the element returned.
//Don't forget the length parameter.

int& getLargestElement(int *array, int length)
{
	for (int index = 0; index < length - 1; ++index)
	{
		if (array[index] > array[index + 1])
		{
			int temp{array[index]};
			array[index] = array[index + 1];
			array[index + 1] = temp;
		}
	}
	return array[length - 1];
}