#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"

class FulltimeEmployee : public Employee {
private:
    double bonus;
public:
    FulltimeEmployee(int id, double salary, double bonus);
    void showInfo() const override;
    double calculate() const override;
};

#endif