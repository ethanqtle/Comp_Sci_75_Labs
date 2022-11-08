// This program has two functions: main and displayMessage
#include <iostream>
using namespace std;

//****************************************
// Definition of function displayMessage *
//****************************************

void displayMessage()
{
    cout << "Hello from the function displayMessage.\n";
}

//****************************************
// Funtion main                          *
//****************************************

int main()
{
    cout << "Hello from main.\n";
    for (int count = 0; count < 5; count++)
        displayMessage(); // Call displayMessage
    cout << "Back in function main again.\n";
    return 0;
}
