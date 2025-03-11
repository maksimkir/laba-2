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
class FulltimeEmployee : public Employee {
public:
    double bonus;
public:
    FulltimeEmployee(int id,double salary , double bonus):Employee(id ,salary), bonus(bonus) {}
    void showInfo() const {
        cout<<"Full-Time Employee: "<< id<<endl<<"Salaty: "<<salary<<endl<<"Bonus: "<<bonus<<endl;
    }
    double calculate() const {
        return salary + bonus;
    }
};