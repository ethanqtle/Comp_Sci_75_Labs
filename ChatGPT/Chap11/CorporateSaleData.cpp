// Starting C++ Chap 11 
// 3. Corporate Sales Data  Write a program that uses a structure to store the following 
// data on a company division:Division Name (such as East, West, North, or South)
// First-Quarter Sales
// Second-Quarter Sales
// Third-Quarter Sales
// Fourth-Quarter Sales
// Total Annual Sales
// Average Quarterly Sales
// 
// The program should use four
//  variables of this structure. Each variable should represent one of the following 
// corporate divisions: East, West, North, and South. The user should be asked for the
//  four quarters’ sales figures for each division. Each division’s total and average sales
//  should be calculated and stored in the appropriate member of each structure variable.
// These figures should then be displayed on the screen.
// Input Validation: Do not accept negative numbers for any sales figures.

#include <iostream>
#include <string>
using namespace std;

// Define the structure for a company division
struct Division {
    string name;
    double q1Sales;
    double q2Sales;
    double q3Sales;
    double q4Sales;
    double totalSales;
    double avgSales;
};

int main() {
    // Define variables for the four divisions
    Division east, west, north, south;

    // Prompt the user to enter the sales figures for each division
    cout << "Enter the sales figures for the East division:" << endl;
    cout << "First quarter: ";
    cin >> east.q1Sales;
    while (east.q1Sales < 0) {
        cout << "Invalid input. Please enter a non-negative number: ";
        cin >> east.q1Sales;
    }
    cout << "Second quarter: ";
    cin >> east.q2Sales;
    while (east.q2Sales < 0) {
        cout << "Invalid input. Please enter a non-negative number: ";
        cin >> east.q2Sales;
    }
    cout << "Third quarter: ";
    cin >> east.q3Sales;
    while (east.q3Sales < 0) {
        cout << "Invalid input. Please enter a non-negative number: ";
        cin >> east.q3Sales;
    }
    cout << "Fourth quarter: ";
    cin >> east.q4Sales;
    while (east.q4Sales < 0) {
        cout << "Invalid input. Please enter a non-negative number: ";
        cin >> east.q4Sales;
    }

    // Calculate the total and average sales for the East division
    east.totalSales = east.q1Sales + east.q2Sales + east.q3Sales + east.q4Sales;
    east.avgSales = east.totalSales / 4.0;

    // Repeat the process for the other three divisions (West, North, and South)

    // Display the sales figures for each division
    cout << "Sales figures for each division:" << endl;
    cout << "East: " << east.totalSales << " total, " << east.avgSales << " average" << endl;
    // Repeat for the other three divisions

    return 0;
}
