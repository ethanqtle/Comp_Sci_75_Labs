#include <iostream>
#include <cstring>

using namespace std;
void printArray(int *arrayData, int arraySize);
void initArray(int *arrayData, int arraySize);
int *reverseArray(int *array, int arraySize);
int main()
{
    int arraySize;
    cout << "Please input the array size\n";
    cin >> arraySize;
    int *arrayData = new int[arraySize];
    initArray(arrayData, arraySize);
    cout << "Original Array: \n";
    printArray(arrayData, arraySize);
    int *revData = reverseArray(arrayData, arraySize);
    cout << "Reverse Array: \n";
    printArray(revData, arraySize);

    return 0;
}

void printArray(int *arrayData, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        cout << arrayData[i] << " ";
    cout << endl;
}
void initArray(int *arrayData, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        arrayData[i] = i * i;
    }
}
int *reverseArray(int *array, int arraySize){
    int *reverseArray = new int[arraySize];
    for (int i = 0; i < arraySize; i++){
        int reverseIndex = arraySize - 1 - i;
        reverseArray[reverseIndex] = array[i];

    }
    return reverseArray;
}

