#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
class Date
{
private:
    int month;
    int day;
    int year;

    const string monthName[13] = {
        "NotAMonth" // Index 0 is not a month
        ,
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    const string getMonthName()
    {
        return monthName[this->month];
    };

public:
    Date(int month, int day, int year)
    {
        this->month = month;
        this->day = day;
        this->year = year;
    }

    bool setMonth(int month)
    {
        if (month < 1 || month > 12)
        {
            return false;
        }
        else
        {
            this->month = month;
            return true;
        }
    }

    bool setDay(int day)
    {
        if (day < 1 || day > 31)
        {
            return false;
        }
        else
        {
            this->day = day;
            return true;
        }
    }

    void setYear(int year)
    {
        this->year = year;
    }

    void printDate1()
    {
        cout << setw(2) << setfill('0')
             << this->month << "/"
             << setw(2) << setfill('0')
             << this->day << "/"
             << setw(2) << setfill('0')
             << (this->year % 100)
             << endl;
    }

    void printDate2()
    {
        cout << getMonthName() << " "
             << setw(2) << setfill('0')
             << this->day << ", "
             << this->year
             << endl;
        ;
    }

    void printDate3()
    {
        cout
            << setw(2) << setfill('0')
            << this->day << " "
            << getMonthName() << " "
            << this->year
            << endl;
        ;
    }
};

int main()
{
    Date myDate(12, 25, 2010);
    myDate.printDate1();
    myDate.printDate2();
    myDate.printDate3();
    return 0;
}
