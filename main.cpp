#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

class ICalculatable {
public:
    virtual double calculateSalary() const = 0;
    virtual ~ICalculatable() = default;
};

class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
    void showInfoStatic() const {
        cout << "[STATIC] Name: " << name << ", Age: " << age << endl;
    }
    virtual void showInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    virtual ~Person() {}
};

class Employee : public Person, public ICalculatable {
protected:
    int id;
    static int employeeCount;
public:
    Employee(string name, int age, int id) : Person(name, age), id(id) {
        employeeCount++;
    }

    Employee(const Employee& other) : Person(other), id(other.id) {
        employeeCount++;
    }

    Employee(Employee&& other) noexcept : Person(move(other)), id(other.id) {
        other.id = 0;
    }

    Employee& operator=(const Employee& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            id = other.id;
        }
        return *this;
    }

    Employee& operator=(Employee&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            age = other.age;
            id = other.id;
            other.id = 0;
        }
        return *this;
    }

    virtual void showInfo() const override {
        Person::showInfo();
        cout << "ID: " << id << endl;
    }

    virtual ~Employee() {
        employeeCount--;
    }

    string getName() const {
        return name;
    }

    static int getEmployeeCount() {
        return employeeCount;
    }
};

int Employee::employeeCount = 0;

class FulltimeEmployee final : public Employee {
private:
    double baseSalary;
    double bonus;
public:
    FulltimeEmployee(string name, int age, int id, double base, double bonus)
        : Employee(name, age, id), baseSalary(base), bonus(bonus) {}

    double calculateSalary() const override {
        return baseSalary + bonus;
    }

    void showInfo() const override {
        Employee::showInfo();
        cout << "Base Salary: " << baseSalary << ", Bonus: " << bonus << endl;
    }
};

class ParttimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;
public:
    ParttimeEmployee(string name, int age, int id, int hours, double rate)
        : Employee(name, age, id), hoursWorked(hours), hourlyRate(rate) {}

    double calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }

    void showInfo() const override {
        Employee::showInfo();
        cout << "Hours Worked: " << hoursWorked << ", Hourly Rate: " << hourlyRate << endl;
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
        logAction("Employee added");
    }

    void showDepartment() const {
        cout << "\nDepartment: " << name << "\nEmployees:\n";
        for (const auto& emp : employees) {
            emp->showInfo();
            cout << "Total Salary: " << emp->calculateSalary() << "\n\n";
        }
        cout << "Total Employees: " << Employee::getEmployeeCount() << endl;
    }

    void saveToFile(const string& filename) {
        ofstream out(filename);
        for (const auto& emp : employees) {
            out << emp->getName() << endl;
        }
    }

    void logAction(const string& action) const {
        ofstream log("log.txt", ios::app);
        time_t now = time(0);
        log << action << " at " << ctime(&now);
    }
};

bool adminLogin() {
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    return password == "admin52";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    Department dept("IT Department");
    string mode;
    cout << "Select mode (admin/user): ";
    cin >> mode;

    if (mode == "admin") {
        if (!adminLogin()) {
            cout << "Access denied.\n";
            return 0;
        }

        int choice;
        do {
            cout << "\n--- Admin Menu ---\n"
                 << "1. Add Fulltime Employee\n"
                 << "2. Add Parttime Employee\n"
                 << "3. Show Department\n"
                 << "4. Save Employees to File\n"
                 << "0. Exit\n"
                 << "Your choice: ";
            cin >> choice;

            clearScreen();

            if (choice == 1) {
                string name;
                int age, id;
                double base, bonus;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter base salary: ";
                cin >> base;
                cout << "Enter bonus: ";
                cin >> bonus;
                dept.addEmployee(make_unique<FulltimeEmployee>(name, age, id, base, bonus));
            } else if (choice == 2) {
                string name;
                int age, id, hours;
                double rate;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter hours worked: ";
                cin >> hours;
                cout << "Enter hourly rate: ";
                cin >> rate;
                dept.addEmployee(make_unique<ParttimeEmployee>(name, age, id, hours, rate));
            } else if (choice == 3) {
                dept.showDepartment();
            } else if (choice == 4) {
                dept.saveToFile("employees.txt");
                cout << "Employees saved to file.\n";
            }
        } while (choice != 0);

    } else if (mode == "user") {
        dept.showDepartment();
    } else {
        cout << "Invalid mode\n";
    }

    return 0;
}
