#include <iostream>

using namespace std;

int main()
{
    int n = -1;
    while(n <= 0 || n > 15)
    {
        cout << "Please input a positive integer no greater than 15: " << endl;
        cin >> n;

    }
    for(int i=0; i < n; i++)
    {
        for(int i=0; i < n; i++)
        {
            cout << "X";
        }
        cout << endl;
    }
    return 0;
}
