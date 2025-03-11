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
class PartyEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;
public:
    PartyEmployee(int id, int hourse , double rate): Employee(id,0), hoursWorked(hourse),hourlyRate(rate){}
    void showInfo() const {
        cout<<"Part-Time Employee ID: "<<id<<endl<<"Hourse Worked: "<<hoursWorked<<endl<<"Hourly Rate: "<<hourlyRate<<endl;
    }
    double calculate() const {
        return hoursWorked + hourlyRate;
    }
};
class PayrollManager {
private:
    vector<Employee*> employees;
public:
    void addEmployee(Employee *e) {
        employees.push_back(e);
    }
    void processpayllor() const {
        for (const auto& employee : employees) {
            employee->showInfo();
            cout <<"Total Pay: "<< employee->calculate() << endl;
        }
    }
    ~PayrollManager() {
        for (auto& e : employees) {
            delete e;
        }
    }
};
int main() {
    PayrollManager manager;
    manager.addEmployee(new FulltimeEmployee (1,3000 , 500));
    manager.addEmployee(new PartyEmployee(2,60 , 20));

    cout<<"Payroll Processing: "<<endl;
    manager.processpayllor();

    return 0;
}