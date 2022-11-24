#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fileName;
    fstream nameFile;
    cout << "Please enter a file name:" << endl;
    cin >> fileName;

    nameFile.open(fileName, ios::in);

    if (nameFile)
    {
        string line;
        int lineCount = 0;
        while ((lineCount < 10 ) && getline(nameFile, line))
        {
            cout << line << endl;
            lineCount++;
        }
        if (lineCount < 10)
        {
            cout << "The entire file " << fileName << " has been displayed." << endl;
        }
        nameFile.close();
    }
    else
    {
        cout << "The file " << fileName << " does not exist." << endl;
    }
    return 0;
}
