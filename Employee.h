#pragma once
#include "Person.h"
#include "ICalculatable.h"

class Employee : public Person, public ICalculatable {
protected:
    int id;
    static int employeeCount;
public:
    Employee(string name, int age, int id);
    Employee(const Employee& other);
    Employee(Employee&& other) noexcept;
    Employee& operator=(const Employee& other);
    Employee& operator=(Employee&& other) noexcept;
    virtual void showInfo() const override;
    virtual ~Employee();
    string getName() const;
};