#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Employee.h"

class Department {
private:
    string name;
    vector<unique_ptr<Employee>> employees;
    void logAction(const string& action) const;
public:
    Department(string name);
    void addEmployee(unique_ptr<Employee> emp);
    void showDepartment() const;
    void saveToFile(const string& filename);
};