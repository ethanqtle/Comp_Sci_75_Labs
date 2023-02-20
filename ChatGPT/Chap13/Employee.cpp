// Employee Class  Write a class named Employee that has the following member variables:
// name—a string that holds the employee’sname
// idNumber—a n int variable that holds the employee’s ID number
// department—a string that holds the name of the department where the employee works
// position—a string that holds the employee’s job title
// 
// The class should have the following constructors:
// 
// A constructor that accepts the following values as arguments and assigns 
// them to the appropriate member variables: 
// employee’s name, employee’s ID number, department, and position.
// 
// A constructor that accepts the following values as arguments and assigns 
// them to the appropriate member variables: employee’s name and ID number.
//  The department and position fields should be assigned an empty string ("").
// A default constructor that assigns empty strings ("") to the name, department,
//  and position member variables, and 0 to the idNumber member variable.
// 
// Write appropriate mutator functions that store values in these member 
// variables and accessor functions that return the values in these member variables.
// Once you have written the class, write a separate program that creates 
// three Employee objects to hold the following data:
    //   Name       ID Number   Department      Position
    // Susan Meyers 47899       Accounting      Vice President
    // Mark Jones   39119       IT              Programmer
    // Joy Rogers   81774       Manufacturing   Engineer
// The program should store this data in the three objects and then display
// the data for each employee on the screen.

#include <iostream>
#include <string>

class Employee {
public:
    // Constructors
    Employee(std::string name, int idNumber, std::string department, std::string position)
        : name(name), idNumber(idNumber), department(department), position(position) {}
    Employee(std::string name, int idNumber)
        : name(name), idNumber(idNumber), department(""), position("") {}
    Employee()
        : name(""), idNumber(0), department(""), position("") {}

    // Mutator functions
    void setName(std::string name) { this->name = name; }
    void setIdNumber(int idNumber) { this->idNumber = idNumber; }
    void setDepartment(std::string department) { this->department = department; }
    void setPosition(std::string position) { this->position = position; }

    // Accessor functions
    std::string getName() const { return name; }
    int getIdNumber() const { return idNumber; }
    std::string getDepartment() const { return department; }
    std::string getPosition() const { return position; }

private:
    std::string name;
    int idNumber;
    std::string department;
    std::string position;
};

int main() {
    Employee susan("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee mark("Mark Jones", 39119, "IT", "Programmer");
    Employee joy("Joy Rogers", 81774, "Manufacturing", "Engineer");

    std::cout << "Name\t\tID Number\tDepartment\tPosition\n";
    std::cout << susan.getName() << "\t" << susan.getIdNumber() << "\t\t" << susan.getDepartment() << "\t\t" << susan.getPosition() << "\n";
    std::cout << mark.getName() << "\t" << mark.getIdNumber() << "\t\t" << mark.getDepartment() << "\t\t\t" << mark.getPosition() << "\n";
    std::cout << joy.getName() << "\t" << joy.getIdNumber() << "\t\t" << joy.getDepartment() << "\t" << joy.getPosition() << "\n";

    return 0;
}
