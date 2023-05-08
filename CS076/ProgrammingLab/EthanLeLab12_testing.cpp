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

// write myQuickSort function to sort array of size arraySize using QuickSort algorithm
// prototype:
void myQuickSort(int array[], int arraySize);

// write myMergeSort function to sort array of size arraySize using MergeSort algorithm
// prototype:
void myMergeSort(int array[], int arraySize);



// write function to sort array of size arraySize with values in {-2, 0, 2}
void countSort(int array[], int arraySize)
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

// implement recursive helperQuickSort function
void helperQuickSort(int array[], int low, int high)
{
    // Order analysis: O(nlogn) for helperQuickSort function
    // since it has to go through the entire array
    // and it has to call itself recursively
    // which is O(logn)
    
    // base case: if low is greater than or equal to high, return
    if (low >= high)
    {
        return;
    }
    // partition the array
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;
    
    while (true)
    {
        // find leftmost element greater than or equal to pivot
        do
        {
            i++;
        } while (array[i] < pivot);
        // find rightmost element less than or equal to pivot
        do
        {
            j--;
        } while (array[j] > pivot);
        // if i is greater than or equal to j, return
        if (i >= j)
        {
            break;
        }
        // swap array[i] with array[j]
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    // recursively call helperQuickSort on left half
    helperQuickSort(array, low, j);
    // recursively call helperQuickSort on right half
    helperQuickSort(array, j + 1, high);
}

// implement myQuickSort function
void myQuickSort(int array[], int arraySize)
{
    // Order analysis: O(nlogn) for myQuickSort function
    // since it has to go through the entire array
    // and it has to call helperQuickSort function
    // which is O(nlogn)
    helperQuickSort(array, 0, arraySize - 1);
}

// implement helperMergeSort function
void helperMergeSort(int array[], int low, int high)
{
    // Order analysis: O(nlogn) for helperMergeSort function
    // since it has to go through the entire array
    // and it has to call itself recursively
    // which is O(logn)
    
    // base case: if low is greater than or equal to high, return
    if (low >= high)
    {
        return;
    }
    // calculate mid
    int mid = (low + high) / 2;
    // recursively call helperMergeSort on left half
    helperMergeSort(array, low, mid);
    // recursively call helperMergeSort on right half
    helperMergeSort(array, mid + 1, high);
    // merge the two halves
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high - low + 1];
    // while i is less than or equal to mid and j is less than or equal to high
    while (i <= mid && j <= high)
    {
        // if array[i] is less than or equal to array[j], assign array[i] to temp[k]
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        // else assign array[j] to temp[k]
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    // while i is less than or equal to mid
    while (i <= mid)
    {
        // assign array[i] to temp[k]
        temp[k] = array[i];
        i++;
        k++;
    }
    // while j is less than or equal to high
    while (j <= high)
    {
        // assign array[j] to temp[k]
        temp[k] = array[j];
        j++;
        k++;
    }
    // copy temp to array
    for (int i = low; i <= high; i++)
    {
        array[i] = temp[i - low];
    }
}

// implement myMergeSort function
void myMergeSort(int array[], int arraySize)
{
    // Order analysis: O(nlogn) for myMergeSort function
    // since it has to go through the entire array
    // and it has to call helperMergeSort function
    // which is O(nlogn)
    helperMergeSort(array, 0, arraySize - 1);
}

// implement bubbleSort function to sort array of size arraySize
void bubbleSort(int array[], int arraySize)
{
    // Order analysis: O(n^2) for bubbleSort function
    // since it has to go through the entire array
    // and it has to go through the entire array again
    // which is O(n^2)
    // declare a boolean variable swapped and initialize it to true
    bool swapped = true;
    // while swapped is true
    while (swapped)
    {
        // set swapped to false
        swapped = false;
        // for i from 0 to arraySize - 2
        for (int i = 0; i < arraySize - 1; i++)
        {
            // if array[i] is greater than array[i + 1]
            if (array[i] > array[i + 1])
            {
                // swap array[i] with array[i + 1]
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                // set swapped to true
                swapped = true;
            }
        }
    }
}

// implement selectionSort function to sort array of size arraySize
void selectionSort(int array[], int arraySize)
{
    // Order analysis: O(n^2) for selectionSort function
    // since it has to go through the entire array
    // and it has to go through the entire array again
    // which is O(n^2)
    // for i from 0 to arraySize - 2
    for (int i = 0; i < arraySize - 1; i++)
    {
        // find the index of the smallest element in array[i..arraySize - 1]
        int minIndex = i;
        for (int j = i + 1; j < arraySize; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        // swap array[i] with array[minIndex]
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}


// function to copy array1 to array2 of size arraySize
void copyArray(int array1[], int array2[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        array2[i] = array1[i];
    }
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
    int* inputArray = new int[arraySize];
    
    fillArray(inputArray, arraySize);

    copyArray(inputArray, array, arraySize);
    cout << "Array before sorting: ";
    printArray(array, arraySize);

    countSort(array, arraySize);
    cout << "Array after countSort: ";
    printArray(array, arraySize);

    copyArray(inputArray, array, arraySize);
    cout << "Array before sorting: ";
    printArray(array, arraySize);

    bubbleSort(array, arraySize);
    cout << "Array after bubbleSort: ";
    printArray(array, arraySize);

    return 0;
}
