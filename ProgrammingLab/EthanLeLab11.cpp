#include <iostream>
#include <cstring>

using namespace std;
void printReverse(char *strIn);
int main()
{
    string myString;
    cout << "Please enter a string: " << endl;
    cin >> myString;
    cout << "In reverse:" << endl;
    printReverse((char *) myString.c_str());
    return 0;
}

void printReverse(char *strIn)
{
    int strLength = strlen(strIn);
    for (int i = strLength - 1; i >= 0; i--)
        cout << *(strIn + i);
    cout << endl;
}