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

//Private member function that converts int 'month' into
    const string monthName ()
    {
        static const string monthList[] =
        {
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"
        };
        return monthList[month - 1];
    };
public:
    //Default form for various integers and their values
    Date(int month = 1, int day = 1, int year = 2022)
    {
        this->month = month;
        this->day = day;
        this->year = year;
    }

    //Meant to confirm if each value matches with the
    //requirements for the months, days, and years.
    bool settingMonth(int month)
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

    bool settingDay(int day)
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

    void settingYear(int year)
    {
        this->year = year;
    }

    inline int getMonth()
    {
        return month;
    }

    inline int getDay()
    {
        return day;
    }

    inline int getYear()
    {
        return year;
    }

    void DateFormat1()
    {
        cout << setw(2) << setfill('0') << getMonth() << "/"
             << setw(2) << setfill('0') << getDay() << "/"
             << setw(2) << setfill('0') << (getYear() % 100)
             << endl;
    }

    void DateFormat2()
    {
        cout << monthName() << " "
             << setw(2) << setfill('0')
             << getDay() << ", "
             << getYear() << endl;
    }

    void DateFormat3()
    {
        cout << setw(2) << setfill('0')
             << getDay() << " " << monthName()
             << " " << getYear() << endl;
    }
};

int main()
{
    Date dateToday;
    int month, day, year;

    month = -1;
    while (!dateToday.settingMonth(month))
    {
        cout << "Please enter a month (1-12): ";
        cin >> month;
    }

    day = -1;
    while (!dateToday.settingDay(day))
    {
        cout << "Please enter a day (1-31): ";
        cin >> day;
    }

    cout << "Please enter a year: ";
    cin >> year;
    dateToday.settingYear(year);

    cout << "Here is the date in Format 1:\n";
    dateToday.DateFormat1();

    cout << "Here is the date in Format 2:\n";
    dateToday.DateFormat2();

    cout << "Here is the date in Format 3:\n";
    dateToday.DateFormat3();
    return 0;
}
