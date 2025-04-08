#pragma once
#include "Employee.h"

class FulltimeEmployee final : public Employee {
private:
    double baseSalary;
    double bonus;
public:
    FulltimeEmployee(string name, int age, int id, double base, double bonus);
    double calculateSalary() const override;
    void showInfo() const override;
};