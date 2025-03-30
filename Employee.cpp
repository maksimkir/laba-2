#include "Employee.h"

int Employee::employeeCount = 0;

Employee::Employee(int id, double salary) : id(id), salary(salary) {
    employeeCount++;
}

Employee::Employee(const Employee& other) : id(other.id), salary(other.salary) {
    employeeCount++;
    std::cout << "The copy constructor is called." << std::endl;
}

Employee::Employee(Employee&& other) noexcept : id(other.id), salary(other.salary) {
    other.id = 0;
    other.salary = 0.0;
    std::cout << "Move constructor called" << std::endl;
}

Employee& Employee::setSalary(double newSalary) {
    this->salary = newSalary;
    return *this;
}

int Employee::getEmployeeCount() {
    return employeeCount;
}

void Employee::showInfo() const {
    std::cout << "ID: " << id << "\nSalary: " << salary << std::endl;
}

double Employee::calculate() const {
    return salary;
}

std::ostream& operator<<(std::ostream& os, const Employee& emp) {
    os << "Employee ID: " << emp.id << "\nSalary: " << emp.salary;
    return os;
}

std::istream& operator>>(std::istream& is, Employee& emp) {
    std::cout << "Enter ID: ";
    is >> emp.id;
    std::cout << "Enter Salary: ";
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
