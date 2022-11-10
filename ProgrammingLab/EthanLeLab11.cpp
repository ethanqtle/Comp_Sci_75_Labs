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

    // Search online and found the use of const_cast
    printReverse(const_cast<char *>(myString.c_str()));
    return 0;
}

void printReverse(char *strIn)
{
    int strLength = strlen(strIn);

    // Set ptr to the end of strIn
    char *ptr = strIn + strLength - 1;

    for (int i = 0; i < strLength; i++)
        cout << *(ptr--);
    cout << endl;
}