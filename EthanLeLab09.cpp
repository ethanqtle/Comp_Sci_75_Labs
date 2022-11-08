#include <cstdlib>
#include <iostream>

bool linSearch(int val, int arrayVal[], int arraySize);
bool binSearch(int val, int arrayVal[], int arraySize);

using namespace std;
int main(int argc, char **argv)
{
    int arrayVal[] =
    {
        5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
        1005231, 6545231, 3852085, 7576651, 7881200, 4581002
    };
    int arraySize = sizeof(arrayVal) / sizeof(int);
    int acctID;

    cout << "Please enter a charge account: " << endl;
    cin >> acctID;
    bool foundAcc = linSearch(acctID, arrayVal, arraySize);
    if (foundAcc)
        cout << "The following number was valid: " << acctID << endl;
    else
        cout << "The following number was invalid: " << acctID << endl;

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
}
