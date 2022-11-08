#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double radius;
    double length;
    double PI = 4.0 * atan(1.0);
    cout << "Please input a radius:" << endl;
    cin >> radius;
    cout << "Please input a length:" << endl;
    cin >> length;
    double area = radius * radius * PI;
    double volume = area * length;
    cout << "Area:" << area << endl;
    cout << "Volume:" << volume << endl;

    cout << "size of int == " << sizeof(int) << endl;
    cout << "size of double == " << sizeof(double) << endl;
    cout << "size of float == " << sizeof(float) << endl;
    return 0;
}

