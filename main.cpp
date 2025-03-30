#include <iostream>
#include <vector>
#include <memory>
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
    FulltimeEmployee(string name, int age, int id, double salary, double bonus)
        : Employee(name, age, id, salary), bonus(bonus) {}
    double calculateSalary() const override { return salary + bonus; }
    void showInfo() const override {
        Employee::showInfo();
        cout << "Bonus: " << bonus << endl;
    }
};

class ParttimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;
public:
    ParttimeEmployee(string name, int age, int id, int hours, double rate)
        : Employee(name, age, id, 0), hoursWorked(hours), hourlyRate(rate) {}
    double calculateSalary() const override { return hoursWorked * hourlyRate; }
    void showInfo() const override {
        Employee::showInfo();
        cout << "Hours Worked: " << hoursWorked << "\nHourly Rate: " << hourlyRate << endl;
    }
};

class Department {
private:
    string name;
    vector<unique_ptr<Employee>> employees;
public:
    Department(string name) : name(name) {}
    void addEmployee(unique_ptr<Employee> emp) {
        employees.push_back(move(emp));
    }
    void showDepartment() const {
        cout << "Department: " << name << "\nEmployees:\n";
        for (const auto& emp : employees) {
            emp->showInfo();
            cout << "Total Salary: " << emp->calculateSalary() << "\n\n";
        }
    }
};

int main() {
    Department itDept("IT Department");
    itDept.addEmployee(make_unique<FulltimeEmployee>("John Doe", 30, 1, 5000, 1000));
    itDept.addEmployee(make_unique<ParttimeEmployee>("Jane Smith", 25, 2, 50, 20));

    itDept.showDepartment();
    return 0;
}
