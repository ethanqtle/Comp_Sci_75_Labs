#include <iostream>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;
public:
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
};

void Date::setMonth(int m)
{
    month = m;
}

void Date::setDay(int d)
{
    day = d;
}

void Date::setYear(int y)
{
    year = y;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

int Date::getYear() const
{
    return year;
}

int main()
{
    Date number;
    int monthNumber = -1;
    int dayNumber = -1;
    int yearNumber;
    string month;

    while (monthNumber < 1 || monthNumber > 12)
    {
        cout << "Please enter a number from 1 to 12 for the month: ";
        cin >> monthNumber;
    };
    while (dayNumber < 1 || dayNumber > 31)
    {
        cout << "Please enter a number from 1 to 31 for the day: ";
        cin >> dayNumber;
    };
    cout << "Please enter a number for the year: ";
    cin >> yearNumber;

    number.setMonth(monthNumber);
    number.setDay(dayNumber);
    number.setYear(yearNumber);

    if (monthNumber == 1)
    {
        month = "January";
    }
    else if (monthNumber == 2)
    {
        month = "February";
    }
    else if (monthNumber == 3)
    {
        month = "March";
    }
    else if (monthNumber == 4)
    {
        month = "April";
    }
    else if (monthNumber == 5)
    {
        month = "May";
    }
    else if (monthNumber == 6)
    {
        month = "June";
    }
    else if (monthNumber == 7)
    {
        month = "July";
    }
    else if (monthNumber == 8)
    {
        month = "August";
    }
    else if (monthNumber == 9)
    {
        month = "September";
    }
    else if (monthNumber == 10)
    {
        month = "October";
    }
    else if (monthNumber == 11)
    {
        month = "November";
    }
    else if (monthNumber == 12)
    {
        month = "December";
    };

    cout << "Here is the date:\n";
    cout << number.getMonth() << "/" << number.getDay() << "/" << number.getYear() << endl;
    cout << month << " " << number.getDay() << ", " << number.getYear() << endl;
    cout << number.getDay() << " " << month << ", " << number.getYear() << endl;
    return 0;
}
