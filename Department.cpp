#include "Department.h"
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

Department::Department(string name) : name(name) {}

void Department::addEmployee(unique_ptr<Employee> emp) {
    employees.push_back(move(emp));
    logAction("Added employee");
}

void Department::showDepartment() const {
    cout << "Department: " << name << "\nEmployees:\n";
    for (const auto& emp : employees) {
        emp->showInfo();
        cout << "Total Salary: " << emp->calculateSalary() << "\n\n";
    }
}

void Department::saveToFile(const string& filename) {
    ofstream out(filename);
    for (const auto& emp : employees) {
        out << emp->getName() << endl;
    }
}

void Department::logAction(const string& action) const {
    ofstream log("log.txt", ios::app);
    time_t now = time(0);
    log << action << " at " << ctime(&now);
}