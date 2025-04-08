#include "Employee.h"

int Employee::employeeCount = 0;

Employee::Employee(string name, int age, int id) : Person(name, age), id(id) {
    employeeCount++;
}

Employee::Employee(const Employee& other) : Person(other), id(other.id) {
    employeeCount++;
}

Employee::Employee(Employee&& other) noexcept : Person(move(other)), id(other.id) {
    other.id = 0;
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        id = other.id;
    }
    return *this;
}

Employee& Employee::operator=(Employee&& other) noexcept {
    if (this != &other) {
        name = move(other.name);
        age = other.age;
        id = other.id;
        other.id = 0;
    }
    return *this;
}

void Employee::showInfo() const {
    Person::showInfo();
    cout << "ID: " << id << endl;
}

Employee::~Employee() {
    employeeCount--;
}

string Employee::getName() const {
    return name;
}