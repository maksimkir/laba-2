#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;


class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void showInfo() const {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
    virtual ~Person() {}
};

class Employee : public Person {
protected:

    int id;
    double salary;
    static int employeeCount;
public:
    Employee(string name, int age, int id, double salary)
        : Person(name, age), id(id), salary(salary) { employeeCount++; }

    Employee(const Employee& other) : Person(other), id(other.id), salary(other.salary) {
        employeeCount++;
        cout << "Copy constructor called." << endl;
    }

    Employee(Employee&& other) noexcept : Person(other), id(other.id), salary(other.salary) {
        other.id = 0;
        other.salary = 0.0;
        cout << "Move constructor called" << endl;
    }

    Employee& operator=(const Employee& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            id = other.id;
            salary = other.salary;
        }
        return *this;
    }

    Employee& operator=(Employee&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            age = other.age;
            id = other.id;
            salary = other.salary;
            other.id = 0;
            other.salary = 0.0;
        }
        return *this;
    }

    virtual double calculateSalary() const { return salary; }
    virtual void showInfo() const override {
        Person::showInfo();
        cout << "ID: " << id << "\nSalary: " << salary << endl;
    }
    virtual ~Employee() { employeeCount--; }
};

int Employee::employeeCount = 0;


class FulltimeEmployee : public Employee {
private:
    double bonus;
public:
    FulltimeEmployee(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void showInfo() const override {
        cout << "Full-Time Employee: " << id << "\nSalary: " << salary << "\nBonus: " << bonus << endl;
    }

    double calculate() const override {
        return salary + bonus;
    }
};

class ParttimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;
public:
    ParttimeEmployee(int id, int hours, double rate) : Employee(id, 0), hoursWorked(hours), hourlyRate(rate) {}

    void showInfo() const override {
        cout << "Part-Time Employee ID: " << id << "\nHours Worked: " << hoursWorked << "\nHourly Rate: " << hourlyRate << endl;
    }

    double calculate() const override {
        return hoursWorked * hourlyRate;
    }
};

class PayrollManager {
private:
    vector<Employee*> employees;

public:
    void addEmployee(Employee* e) {
        employees.push_back(e);
    }

    void processPayroll() const {
        for (const auto& employee : employees) {
            employee->showInfo();
            cout << "Total Pay: " << employee->calculate() << "\n";
        }
    }

    ~PayrollManager() {
        for (auto& e : employees) {
            delete e;
        }
    }
};

int main() {
    SetConsoleOutputCP(65001);
;    PayrollManager manager;
    manager.addEmployee(new FulltimeEmployee(1, 3000, 500));
    manager.addEmployee(new ParttimeEmployee(2, 60, 20));

    cout << "Payroll Processing: " << endl;
    manager.processPayroll();

    // Демонстрація статичного поля
    cout << "Total Employees: " << Employee::getEmployeeCount() << endl;

    // Демонстрація унарного оператора "++"
    Employee e1(3, 2000);
    ++e1;
    cout << e1 << endl;

    // Демонстрація бінарного оператора "+"
    Employee e2(4, 1500);
    Employee e3 = e1 + e2;
    cout << e3 << endl;

    // Демонстрація перевантаженого оператора вводу
    Employee e4(0, 0);
    cin >> e4;
    cout << e4 << endl;

    return 0;
}