#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee {
protected:
    int id;
    double salary;
    static int employeeCount;

public:
    Employee(int id, double salary);
    Employee(const Employee& other);
    Employee(Employee&& other) noexcept;
    Employee& setSalary(double newSalary);
    static int getEmployeeCount();
    virtual void showInfo() const;
    virtual double calculate() const;
    friend ostream& operator<<(ostream& os, const Employee& emp);
    friend istream& operator>>(istream& is, Employee& emp);
    Employee& operator++();
    Employee operator+(const Employee& other) const;
    virtual ~Employee();
};

#endif