// Please do the following:

// Write a program that randomly fills an array of integers and then sorts it.
//  The array size is entered by the user and the values are chosen at
//  random in {-2, 0, 2}. Analyze the time complexity of your program.
// Save the source code in file  Exercise01.cpp.  

// write a sort function of arrays of integers values randomly selected in {-2, 0, 2}
// using radix sort

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// write function to print array of size arraySize
void printArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

// fill array of size arraySize with random values in {-2, 0, 2}
void fillArray(int array[], int arraySize)
{
    // declare a fixed array of size 3 with values -2, 0, 2
    int values[3] = { -2, 0, 2 };
    for (int i = 0; i < arraySize; i++)
    {
        // generate a random index in [0, 2]
        int index = rand() % 3;
        // assign the value at index to array[i]
        array[i] = values[index];
    }
}

// write function to count the number of elements in array of size arraySize with a value
// of value prototype:
int count(int array[], int arraySize, int value);


// write function to sort array of size arraySize with values in {-2, 0, 2}
void sort(int array[], int arraySize)
{
    // Order analysis: O(n) for sort function
    // since it has to go through the entire array with
    // 3 calls to count function
    // and 3 for loops to assign values to array elements
    // which are all O(n)
    int countNeg2 = count(array, arraySize, -2);
    int count0 = count(array, arraySize, 0);
    // Don't need to count 2 because it's the only value left
    // int count2 = count(array, arraySize, 2);

    for (int i = 0; i < countNeg2; i++)
    {
        array[i] = -2;
    }
    for (int i = countNeg2; i < countNeg2 + count0; i++)
    {
        array[i] = 0;
    }
    for (int i = countNeg2 + count0; i < arraySize; i++)
    {
        array[i] = 2;
    }
}

int count(int array[], int arraySize, int value)
{
    // Order analysis: O(n) for count function 
    // since it has to go through the entire array
    int count = 0;
     for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == value)
        {
            count++;
        }
    }
    return count;
}

// write main function to test
int main()
{
    srand(time(0));

    int arraySize;
    cout << "Enter array size: ";
    cin >> arraySize;

    // create array of size arraySize using new
    int* array = new int[arraySize];

    fillArray(array, arraySize);
    cout << "Array before sorting: ";
    printArray(array, arraySize);

    sort(array, arraySize);
    cout << "Array after sorting: ";
    printArray(array, arraySize);

    return 0;
}
