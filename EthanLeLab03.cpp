#include <iostream>
//This program will read three edges for a triangle and compute the perimeter.
using namespace std;

int main()
{
    double edge1, edge2, edge3;
    double perimeter;
    cout << "Input 3 edges and separate each value by a space: " << endl;
    cin >> edge1 >> edge2 >> edge3;
    perimeter = (edge1 + edge2 + edge3);
    cout << "The triangle perimeter is: " << perimeter << endl;
    return 0;
}
