#include <iostream>
#include <cstring>

using namespace std;
void printReverse(char *strIn);
int main()
{
   char myString[1024];
   cout << "Please enter a string: " << endl;
   cin >> myString;
   printReverse(myString);
   return 0;
}

void printReverse(char *strIn)
{
    int strLength = strlen(strIn);
    for (int i = strLength - 1; i >= 0; i--)
        cout << *(strIn + i);
}