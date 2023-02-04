#include <cstdlib>
#include <iostream>

bool linSearch(int val, int arrayVal[], int arraySize);

using namespace std;
int main(int argc, char **argv)
{
    int winningVal[] =
        {
            13579, 26791, 26792, 33445, 55555,
            62483, 77777, 79422, 85647, 93121
        };
    int arraySize = sizeof(winningVal) / sizeof(int);
    int ticketID;

    cout << "Please enter a 5 digit lottery number: " << endl;
    cin >> ticketID;
    bool foundAcc = linSearch(ticketID, winningVal, arraySize);
    if (foundAcc)
        cout << "This is a winning number!: " << ticketID << endl;
    else
        cout << "This was not a winning number.: " << ticketID << endl;

    return 0;
}

bool linSearch(int val, int arrayVal[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (val == arrayVal[i])
            return true;
    }
    return false;
};