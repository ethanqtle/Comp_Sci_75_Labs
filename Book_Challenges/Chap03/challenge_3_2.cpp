// There are three seating categories at a stadium. For a softball game,
// Class A seats cost $15, Class B seats cost $12, and Class C seats 
// cost $9. Write a program that asks how many tickets for each class
// of seats were sold, then displays the amount of income generated 
// from ticket sales. Format your dollar amount in fixed-point notation, 
// with two decimal places of precision, and be sure the decimal point is always displayed.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int classA, classB, classC;
    double incomeA, incomeB, incomeC, totalIncome;
    
    cout << "How many Class A seats were sold? ";
    cin >> classA;
    cout << "How many Class B seats were sold? ";
    cin >> classB;
    cout << "How many Class C seats were sold? ";
    cin >> classC;
    
    incomeA = classA * 15;
    incomeB = classB * 12;
    incomeC = classC * 9;
    totalIncome = incomeA + incomeB + incomeC;
    
    cout << setprecision(2) << fixed;
    cout << "Income from Class A seats: $" << incomeA << endl;
    cout << "Income from Class B seats: $" << incomeB << endl;
    cout << "Income from Class C seats: $" << incomeC << endl;
    cout << "Total income from ticket sales: $" << totalIncome << endl;
    
    return 0;
}

