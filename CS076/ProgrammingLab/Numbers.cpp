// ChatGPT 4.0 spec: 

// Design a class in C++ Numbers that can be used to translate whole dollar amounts in the range from 0 to 9999 
// into and English description of the number. For example number 713 into the string seven hundred thirteen. 
// The class should have a single integer member variable: int number;
// static string lessThan20[] 
// For example you can use 3 static string members for lessThan20, hundred, and thousand

// Example test case 713 and 8023
// 
// I would like to modify the code to 'using namespace std' style

#include <iostream>
#include <string>

using namespace std;

class Numbers {
private:
    int number;
    static string lessThan20[];
    static string tens[];
    static string hundred;
    static string thousand;

public:
    Numbers(int num) : number(num) {}

    string toString() {
        if (number == 0) {
            return "zero";
        }

        string result;

        // Handle thousands
        if (number >= 1000) {
            result += lessThan20[number / 1000] + " " + thousand + " ";
            number %= 1000;
        }

        // Handle hundreds
        if (number >= 100) {
            result += lessThan20[number / 100] + " " + hundred + " ";
            number %= 100;
        }

        // Handle tens
        if (number >= 20) {
            result += tens[number / 10 - 2] + " ";
            number %= 10;
        }

        // Handle ones
        if (number > 0) {
            result += lessThan20[number];
        }

        return result;
    }
};

string Numbers::lessThan20[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
};

string Numbers::tens[] = {
    "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

int main() {
    int num1 = 713;
    Numbers n1(num1);
    cout << n1.toString() << endl;  // "seven hundred thirteen"

    int num2 = 8023;
    Numbers n2(num2);
    cout << n2.toString() << endl;  // "eight thousand twenty three"

    cout << "Please enter a test num [0-9999] :";
    cin >> num1;
    n2 = Numbers(num1);
    cout << n2.toString() << endl;

    return 0;
}
