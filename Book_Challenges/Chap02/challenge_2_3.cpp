// Write a program that will compute the total sales tax on a $95 purchase.
// Assume the state sales tax is 4 percent, and the county sales tax is 2 percent.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double purchase = 95;
    double stateTax = 0.04;
    double countyTax = 0.02;
    double totalTax = purchase * (stateTax + countyTax);
    cout << "The total sales tax on a $" << purchase << " purchase is $" << totalTax << endl;
    return 0;
}


