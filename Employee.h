#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

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
    friend std::ostream& operator<<(std::ostream& os, const Employee& emp);
    friend std::istream& operator>>(std::istream& is, Employee& emp);
    Employee& operator++();
    Employee operator+(const Employee& other) const;
    virtual ~Employee();
};

#endif // EMPLOYEE_H
