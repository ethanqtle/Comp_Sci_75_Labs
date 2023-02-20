// Date
// Design a class called Date. The class should store 
// a date in three integers: month, day, and year.
// There should be member functions to print the date 
// in the following forms:
// 12/25/2021
// December 25, 2021
// 25 December 2021
//   Demonstrate the class by writing a complete 
// program implementing it.
// Input Validation: Do not accept values for the day greater
//  than 31 or less than 1. Do not accept values for the 
// month greater than 12 or less than 1.

#include <iostream>
#include <string>

class Date {
public:
    // Constructor
    Date(int m, int d, int y)
        : month(m), day(d), year(y) {}

    // Member functions
    void printDate1() {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }

    void printDate2() {
        std::string monthName = getMonthName();
        std::cout << monthName << " " << day << ", " << year << std::endl;
    }

    void printDate3() {
        std::string monthName = getMonthName();
        std::cout << day << " " << monthName << " " << year << std::endl;
    }

private:
    int month, day, year;

    // Helper function to get the month name
    std::string getMonthName() {
        std::string monthNames[12] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        return monthNames[month - 1];
    }
};

int main() {
    int month, day, year;

    // Get user input for the date
    std::cout << "Enter the month (1-12): ";
    std::cin >> month;

    while (month < 1 || month > 12) {
        std::cout << "Invalid input. Please enter a value between 1 and 12: ";
        std::cin >> month;
    }

    std::cout << "Enter the day (1-31): ";
    std::cin >> day;

    while (day < 1 || day > 31) {
        std::cout << "Invalid input. Please enter a value between 1 and 31: ";
        std::cin >> day;
    }

    std::cout << "Enter the year: ";
    std::cin >> year;

    // Create a Date object with the user input
    Date date(month, day, year);

    // Print the date in various formats
    date.printDate1();
    date.printDate2();
    date.printDate3();

    return 0;
}
