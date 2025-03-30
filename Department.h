// department.h
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>

class Department {
private:
    std::string name;
    std::vector<std::string> employees;

public:
    Department(const std::string& dept_name);
    void addEmployee(const std::string& employee_name);
    void removeEmployee(const std::string& employee_name);
    void displayEmployees() const;
    std::string getName() const;
};

#endif // DEPARTMENT_H