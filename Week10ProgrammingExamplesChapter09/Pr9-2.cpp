// This program stores the address of a variable in a pointer.
#include <cstddef>
#include <iostream>
using namespace std;

int main()
{
   int x = 25;				// int variable
int* ptr {};

   ptr = &x;      // Store the address of x in ptr
   cout << "The value in x is " << x << endl;
   cout << "The address of x is " << ptr << endl;
   return 0;
}
