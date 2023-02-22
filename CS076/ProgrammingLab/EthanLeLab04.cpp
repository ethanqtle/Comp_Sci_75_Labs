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
