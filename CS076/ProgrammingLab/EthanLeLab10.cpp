#include <iostream>
using namespace std;

// Function prototypes
template <typename T>
void quickSort(T list[], int arraySize);
template <typename T>
void quickSort(T list[], int first, int last);
template <typename T>
int partition(T list[], int first, int last);

template <typename T>
void quickSort(T list[], int arraySize)
{
    quickSort(list, 0, arraySize - 1);
}

template <typename T>
void quickSort(T list[], int first, int last)
{
    if (last > first)
    {
        int pivotIndex = partition(list, first, last);
        quickSort(list, first, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, last);
    }
}

// Partition the array list[first..last]
template <typename T>
int partition(T list[], int first, int last)
{
    T pivot = list[first]; // Choose the first element as the pivot
    int low = first + 1;   // Index for forward search
    int high = last;       // Index for backward search

    while (high > low)
    {
        // Search forward from left
        while (low <= high && list[low] <= pivot)
            low++;

        // Search backward from right
        while (low <= high && list[high] > pivot)
            high--;

        // Swap two elements in the list
        if (high > low)
        {
            T temp = list[high];
            list[high] = list[low];
            list[low] = temp;
        }
    }

    while (high > first && list[high] >= pivot)
        high--;

    // Swap pivot with list[high]
    if (pivot > list[high])
    {
        list[first] = list[high];
        list[high] = pivot;
        return high;
    }
    else
    {
        return first;
    }
}

int main()
{
    const int SIZE = 10;
    int list[SIZE];

    cout << "Enter 10 integers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> list[i];

    quickSort(list, SIZE);

    cout << "The sorted array is ";
    for (int i = 0; i < SIZE; i++)
        cout << list[i] << " ";

    cout << endl;
    return 0;
}
