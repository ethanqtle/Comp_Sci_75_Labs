#include <iostream>
#include <iomanip>

using namespace std;
double calculateRetail(double wholesaleCost, double markupPercent);

int main()
{
    double wholesaleCost;
    double markupPercent;
    cout << "Please input a wholesale cost: " << endl;
    cin >> wholesaleCost;

    cout << "Please input a markup percentage: " << endl;
    cin >> markupPercent;

    cout.setf(ios::fixed); //This will always print with 2 decimal places
    cout << setprecision(2)
         << "Retail price = $"
         << calculateRetail(wholesaleCost, markupPercent)
         << endl;
    return 0;
}

double calculateRetail (double wholesaleCost, double markupPercent)
{
    return wholesaleCost*(1.0 + markupPercent/100.0);

}
