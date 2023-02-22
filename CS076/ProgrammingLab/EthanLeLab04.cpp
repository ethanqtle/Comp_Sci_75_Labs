// Design a class named Employee. The class should keep the following information in
// member variables:
// 
// • Employee name
// • Employee number
// • Hire date
// 
// 
// Write one or more constructors and the appropriate accessor and mutator functions
// for the class. Next, write a class named ProductionWorker that is derived from the
// Employee class. The ProductionWorker class should have member variables to hold the
// following information:
// 
// • Shift (an integer)
// • Hourly pay rate (a double)
// 
// The workday is divided into two shifts: day and night. The shift variable will hold
// an integer value representing the shift that the employee works. The day shift is
// shift 1 and the night shift is shift 2. Write one or more constructors and the 
// appropriate accessor and mutator functions for the class. Demonstrate the classes
// by writing a program that uses a ProductionWorker object.

#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    Employee(string name, int number, string hireDate) {
        this->name = name;
        this->number = number;
        this->hireDate = hireDate;
    }

    void setName(string name) {
        this->name = name;
    }

    void setNumber(int number) {
        this->number = number;
    }

    void setHireDate(string hireDate) {
        this->hireDate = hireDate;
    }

    string getName() const {
        return name;
    }

    int getNumber() const {
        return number;
    }

    string getHireDate() const {
        return hireDate;
    }

private:
    string name;
    int number;
    string hireDate;
};

class ProductionWorker : public Employee {
public:
    ProductionWorker(string name, int number, string hireDate, int shift, double hourlyPayRate)
        : Employee(name, number, hireDate) {
        this->shift = shift;
        this->hourlyPayRate = hourlyPayRate;
    }

    void setShift(int shift) {
        this->shift = shift;
    }

    void setHourlyPayRate(double hourlyPayRate) {
        this->hourlyPayRate = hourlyPayRate;
    }

    int getShift() const {
        return shift;
    }

    double getHourlyPayRate() const {
        return hourlyPayRate;
    }

private:
    int shift;
    double hourlyPayRate;
};

int main() {
    ProductionWorker worker("John Smith", 123, "01/01/2022", 1, 15.0);
    cout << "Name: " << worker.getName() << endl;
    cout << "Number: " << worker.getNumber() << endl;
    cout << "Hire Date: " << worker.getHireDate() << endl;
    cout << "Shift: " << worker.getShift() << endl;
    cout << "Hourly Pay Rate: " << worker.getHourlyPayRate() << endl;
    return 0;
}
