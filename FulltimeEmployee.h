#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"
#include <string>

class FulltimeEmployee : public Employee {
private:
    double bonus;

public:

    FulltimeEmployee(std::string name, int age, int id, double salary, double bonus);
    double calculateSalary() const;
    void showInfo() const override;
};

#endif // FULLTIMEEMPLOYEE_H
