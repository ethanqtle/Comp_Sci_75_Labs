#include <iostream>
#include <cstring>

using namespace std;
void printReverse(char *strIn);
int main()
{
    const int MAX_STRING = 100;
    char myString[MAX_STRING];
    cout << "Please enter a string: " << endl;
    cin.getline(myString, MAX_STRING);
    cout << "In reverse:" << endl;

    printReverse(myString);
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