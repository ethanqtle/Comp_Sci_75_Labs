#include <iostream>
using namespace std;
void bubbleSortA(int *intArray, int size);
void readArray(int *intArray, int size);
void printScore(int *scoreA, int size);
double avgScore(int *scoreA, int size);

int main(void)
{

    int numScore = -1;
    while (numScore < 0)
    {
        cout << "Please enter number of scores: " << endl;
        cin >> numScore;
    }

    int *scoreA = new int[numScore];
    readArray(scoreA, numScore);
    bubbleSortA(scoreA, numScore);
    cout << "\n"
         << "Sorted list of arrays:" << endl;
    printScore(scoreA, numScore);

    double calcAvgScore = avgScore(scoreA, numScore);
    cout << "\n"
         << "The average score is: " << calcAvgScore << endl;
    delete[] scoreA;
    return 0;
}

void readArray(int *intArray, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        cin >> *(intArray + i);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSortA(int *intArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (*(intArray + j - 1) > *(intArray + j))
            {
                swap(intArray + j - 1, intArray + j);
            }
        }
    }
}

void printScore(int *scoreA, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(scoreA + i) << endl;
    }
}
double avgScore(int *scoreA, int size)
{
    double totalScore = 0.0;
    for (int i = 0; i < size; i++)
    {
        totalScore += *(scoreA + i);
    }
    return totalScore / size;
}
