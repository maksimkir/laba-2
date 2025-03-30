// department.cpp
#include "department.h"
#include <algorithm>
#include <iostream>

Department::Department(const std::string& dept_name) : name(dept_name) {}

void Department::addEmployee(const std::string& employee_name) {
    employees.push_back(employee_name);
}

void Department::removeEmployee(const std::string& employee_name) {
    employees.erase(std::remove(employees.begin(), employees.end(), employee_name), employees.end());
}

void Department::displayEmployees() const {
    std::cout << "Employees in " << name << " department:" << std::endl;
    for (const auto& employee : employees) {
        std::cout << "- " << employee << std::endl;
    }
}

std::string Department::getName() const {
    return name;
}
