#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Date
{
private:
    int month;
    int day;
    int year;

    // getMonthName return a string for the month's name
    const string getMonthName()
    {
        // Use object's month variable => no need to pass in
        switch (month)
        {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";

        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";

        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";

        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Unknown";
        }
    };

public:
    Date(int month=2, int day=17, int year=2006)
    {
        this->month = month;
        this->day = day;
        this->year = year;
    }

    // return true if we can set month
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

    // return true if we can set day
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

    // return true always, there's no validation on year
    void setYear(int year)
    {
        this->year = year;
    }

    inline int getMonth(){ return month;}

    inline int getDay(){ return day;}

    inline int getYear(){ return year;}


    void printDate1()
    {
        cout << setw(2) << setfill('0')
             << getMonth() << "/"
             << setw(2) << setfill('0')
             << getDay() << "/"
             << setw(2) << setfill('0')
             << (getYear() % 100)
             << endl;
    }

    void printDate2()
    {
        cout << getMonthName() << " "
             << setw(2) << setfill('0')
             << getDay() << ", "
             << getYear()
             << endl;
        ;
    }

    void printDate3()
    {
        cout
            << setw(2) << setfill('0')
            << getDay() << " "
            << getMonthName() << " "
            << getYear()
            << endl;
        ;
    }

};


int main()
{
    Date myDate;
    int month, day, year;
    cout << "Please enter a date to print " << endl;

    month = -1;
    while(!myDate.setMonth(month)){
        cout << "Please enter the month (1-12): " << endl;
        cin >> month;
    }

    day = -1;
    while(!myDate.setDay(day)){
        cout << "Please enter the day (1-31): " << endl;
        cin >> day;
    }

    cout << "Please enter the year" << endl;
    cin >> year;
    myDate.setYear(year);

    cout << endl << "Date in format1" << endl;
    myDate.printDate1();

    cout << endl << "Date in format2" << endl;
    myDate.printDate2();

    cout << endl << "Date in format3" << endl;
    myDate.printDate3();

    return 0;
}
