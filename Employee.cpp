#include "Employee.h"

int Employee::employeeCount = 0;

Employee::Employee(int id, double salary) : id(id), salary(salary) {
    employeeCount++;
}

Employee::Employee(const Employee& other) : id(other.id), salary(other.salary) {
    employeeCount++;
    cout << "The copy constructor is called." << endl;
}

Employee::Employee(Employee&& other) noexcept : id(other.id), salary(other.salary) {
    other.id = 0;
    other.salary = 0.0;
    cout << "Move constructor called" << endl;
}

Employee& Employee::setSalary(double newSalary) {
    this->salary = newSalary;
    return *this;
}

int Employee::getEmployeeCount() {
    return employeeCount;
}

void Employee::showInfo() const {
    cout << "ID: " << id << "\nSalary: " << salary << endl;
}

double Employee::calculate() const {
    return salary;
}

ostream& operator<<(ostream& os, const Employee& emp) {
    os << "Employee ID: " << emp.id << "\nSalary: " << emp.salary;
    return os;
}

istream& operator>>(istream& is, Employee& emp) {
    cout << "Enter ID: ";
    is >> emp.id;
    cout << "Enter Salary: ";
    is >> emp.salary;
    return is;
}

Employee& Employee::operator++() {
    salary += 100;
    return *this;
}

Employee Employee::operator+(const Employee& other) const {
    return Employee(id, salary + other.salary);
}

Employee::~Employee() {
    employeeCount--;
}
