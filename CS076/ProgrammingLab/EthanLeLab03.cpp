//  A corporation has six divisions, each responsible for sales to different geographic locations.
// 
//  Design a DivSales class that keeps sales data for a division, with the following members: 
// 
//  • An array with four elements for holding four quarters of sales figures for the division.
// 
//  • A private static variable for holding the total corporate sales for all divisions for
//    the entire year.
// 
//  • A member function that takes four arguments, each assumed to be the sales for a quarter.
//    The value of the arguments should be copied into the array that holds the sales data.
//    The total of the four arguments should be added to the static variable that holds the 
//    total yearly corporate sales.
// 
//  • A function that takes an integer argument within the range of 0–3. The argument is to be 
//    used as a subscript into the division quarterly sales array. The function should return
//    the value of the array element with that subscript.
// 
// Write a program that creates an array of six DivSales objects. The program should ask the 
// user to enter the sales for four quarters for each division. After the data are entered,
// the program should display a table showing the division sales for each quarter. The
// program should then display the total corporate sales for the year

#include <iostream>
using namespace std;

class DivSales {
private:
    double sales[4];
    static double totalCorporateSales;
public:
    void setSales(double q1, double q2, double q3, double q4) {
        sales[0] = q1;
        sales[1] = q2;
        sales[2] = q3;
        sales[3] = q4;
        totalCorporateSales += q1 + q2 + q3 + q4;
    }
    double getQuarterSales(int quarter) {
        return sales[quarter];
    }
    static double getTotalCorporateSales() {
        return totalCorporateSales;
    }
};

// Declared outside of class in a .cpp file
double DivSales::totalCorporateSales = 0.0;

int main() {
    DivSales divisions[6];
    double qSale[4];
    for (int i = 0; i < 6; i++) {
        cout << "Enter sales for division " << i+1 << ":\n";
        for(int j=0;j<4;j++){
            cout << "Quarter " << i << ": ";
            cin >> qSale[j];
        }
        divisions[i].setSales(qSale[0], qSale[1], qSale[2], qSale[3]);
    }
    cout << "\nDivision sales:\n";
    cout << "         Q1        Q2        Q3        Q4\n";
    for (int i = 0; i < 6; i++) {
        cout << "Div " << i+1 << "  ";
        for (int j = 0; j < 4; j++) {
            cout << divisions[i].getQuarterSales(j) << "   ";
        }
        cout << endl;
    }
    cout << "Total corporate sales: " << DivSales::getTotalCorporateSales() << endl;
    return 0;
}
