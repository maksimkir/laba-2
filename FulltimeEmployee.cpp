#include "FulltimeEmployee.h"
#include <iostream>

FulltimeEmployee::FulltimeEmployee(std::string name, int age, int id, double salary, double bonus)
    : Employee(name ,age , id, salary , bonus ), bonus(bonus) {}

double FulltimeEmployee::calculateSalary() const {
    return salary + bonus;

}

void FulltimeEmployee::showInfo() const {
    Employee::showInfo();
    std::cout << "Bonus: " << bonus << std::endl;
}
