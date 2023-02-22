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
double DivSales::totalCorporateSales = 0;

int main() {
    DivSales divisions[6];
    double q1, q2, q3, q4;
    for (int i = 0; i < 6; i++) {
        cout << "Enter sales for division " << i+1 << ":\n";
        cout << "Quarter 1: ";
        cin >> q1;
        cout << "Quarter 2: ";
        cin >> q2;
        cout << "Quarter 3: ";
        cin >> q3;
        cout << "Quarter 4: ";
        cin >> q4;
        divisions[i].setSales(q1, q2, q3, q4);
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
