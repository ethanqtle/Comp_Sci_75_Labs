// Write a function that accepts an array of integers and a number indicating the number of elements as arguments.
// The function should recursively calculate the sum of all the numbers in the array.
// Demonstrate the function in a driver program.
// Ethan Le

#include <iostream>
using namespace std;

int sum(int[], int);

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "The sum of the array is " << sum(arr, 10) << endl;
	return 0;
}

int sum(int arr[], int size)
{
	if (size == 0)
		return 0;
	else
		return arr[size - 1] + sum(arr, size - 1);
}

// Output:

// The sum of the array is 55

// C++ Programming Lab

// CS076 Programming Lab

// Ethan Le

// Lab 9

// Programming Lab

// Post navigation ← Lab 8: C++ Programming Lab