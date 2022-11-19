#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int width;
};

void showRectangle(Rectangle);

// Write the prototype for the getRectangle function here.
Rectangle getRectangle();

int main()
{
    Rectangle rect;

    // Write a statement that assigns the return value of
    // the getRectangle function to the Rectangle structure
    // variable named rect here.
    rect = getRectangle();
    showRectangle(rect);

    return 0;
}

void showRectangle(Rectangle r)
{
    cout << "Length: " << r.length << endl;
    cout << "Width: " << r.width << endl;
};

Rectangle getRectangle()
{
    Rectangle tempRectangle;

    cout << "Enter the length: ";
    cin >> tempRectangle.length;

    cout << "Enter the width: ";
    cin >> tempRectangle.width;

    return tempRectangle;
}