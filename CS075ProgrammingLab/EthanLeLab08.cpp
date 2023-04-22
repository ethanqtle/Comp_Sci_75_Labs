#include <iostream>

using namespace std;
double getRainFallInput(int month);
int main()
{
    const int NUM_MONTH = 12;
    double rainFall[NUM_MONTH];
    double totalRainFall, highestRainFall, lowestRainFall, averageRainFall;
    int lowestMonth, highestMonth;
    highestRainFall = -1.0;
    lowestRainFall = -1.0;
    totalRainFall = 0.0;

    lowestMonth = -1;
    highestMonth = -1;
    for (int month=1; month <= NUM_MONTH; month++)
    {
        double rainFallInput;
        rainFallInput = getRainFallInput(month);
        rainFall[month - 1] = rainFallInput;
        if(highestRainFall < 0.0 || rainFallInput > highestRainFall)
        {
            highestRainFall = rainFallInput;
            highestMonth = month;
        }
        if(lowestRainFall < 0.0 || rainFallInput < lowestRainFall)
        {
            lowestRainFall = rainFallInput;
            lowestMonth = month;
        }
        totalRainFall += rainFallInput;
    }
    averageRainFall = totalRainFall/NUM_MONTH;
    cout << "The total rainfall for this year is " << totalRainFall << "." << endl;
    cout << "The average monthly rainfall is " << averageRainFall << "." << endl;
    cout << "The month with the highest rainfall is " << highestRainFall << "." << endl;
    cout << "The month with the lowest rainfall is " << lowestRainFall << "." << endl;
    return 0;
}

double getRainFallInput(int month)
{
    double rainFallInput = -1.0;
    while(rainFallInput < 0.0)
    {
        cout << "Please input the rainfall for the month: " << month << endl;
        cin >> rainFallInput;
    }
    return rainFallInput;
}
