// Write a function that accepts an array of integers and a number indicating the number of elements as arguments.
// The function should recursively calculate the sum of all the numbers in the array.
// Demonstrate the function in a driver program.
// Ethan Le

#include <iostream>
using namespace std;

int recursiveArraySum(int array[], int numberOfElements)
{
	if (numberOfElements == 0)
		return 0;
	else
		return array[numberOfElements - 1] +
			   recursiveArraySum(array, numberOfElements - 1);
}

int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "The sum of the array is " << recursiveArraySum(arr, 10) << endl;
	return 0;
}