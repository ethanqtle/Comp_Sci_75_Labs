// This program has three functions: main, first, and second
#include <iostream>
using namespace std;

//****************************************
// Definition of function first          *
// This function displasys a message.    *
//****************************************

void first()
{
    cout << "I am now inside the function first.\n";
}

//****************************************
// Definition of function second         *
// This function displasys a message.    *
//****************************************

void second()
{
    cout << "I am now inside the function second.\n";
}

void displayMessage()
{
    cout << "Hello from the function displayMessage.\n";
}

//****************************************
// Funtion main                          *
//****************************************

int main()
{
    cout << "I am starting in function main.\n";
    first();   // Call function first
    second();  // Call function second
    cout << "Back in function main again.\n";
    return 0;
}
