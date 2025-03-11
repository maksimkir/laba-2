#include <iostream>
#include <vector>

using namespace std;

class Employee{
protected:
    int id;
    double salary;
public:
    Employee(int id, int salary):id(id), salary(salary) {}
    void showInfo() const {
        cout << "ID: " << id << endl<< "Salary: "<< salary << endl;
    }
    double calculate() const {
        return salary;
    }
};