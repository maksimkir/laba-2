#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Інтерфейс
class ICalculatable {
public:
    virtual double calculateSalary() const = 0;
    virtual ~ICalculatable() = default;
};

// Базовий клас
class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
    void showInfoStatic() const { // демонстрація статичної прив'язки
        cout << "[STATIC] Name: " << name << ", Age: " << age << endl;
    }
    virtual void showInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    virtual ~Person() {}
};

// Абстрактний клас Employee
class Employee : public Person, public ICalculatable {
protected:
    int id;
    static int employeeCount;
public:
    Employee(string name, int age, int id)
        : Person(name, age), id(id) { employeeCount++; }

    Employee(const Employee& other) : Person(other), id(other.id) {
        employeeCount++;
        cout << "Copy constructor called.\n";
    }

    Employee(Employee&& other) noexcept : Person(other), id(other.id) {
        other.id = 0;
        cout << "Move constructor called\n";
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

    virtual ~Employee() { employeeCount--; }
};

int Employee::employeeCount = 0;

// Повноцінний працівник
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

// Частковий працівник
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

// Відділ
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

void demonstrateStaticBinding(Person p) {
    p.showInfoStatic(); // Статична прив'язка
}

void demonstratePolymorphismByPointer(const Employee* emp) {
    emp->showInfo();
    cout << "Salary: " << emp->calculateSalary() << "\n";
}

void demonstratePolymorphismByReference(const Employee& emp) {
    emp.showInfo();
    cout << "Salary: " << emp.calculateSalary() << "\n";
}

int main() {
    Department itDept("IT Department");

    itDept.addEmployee(make_unique<FulltimeEmployee>("John Doe", 30, 1, 5000, 1000));
    itDept.addEmployee(make_unique<ParttimeEmployee>("Jane Smith", 25, 2, 50, 20));

    itDept.showDepartment();

    cout << "--- Static Binding Demo ---\n";
    Person p("Anna Static", 40);
    demonstrateStaticBinding(p);

    cout << "--- Run-Time Polymorphism by Pointer ---\n";
    FulltimeEmployee fte("Max Mustermann", 35, 3, 6000, 500);
    demonstratePolymorphismByPointer(&fte);

    cout << "--- Run-Time Polymorphism by Reference ---\n";
    ParttimeEmployee pte("Lisa Flexible", 28, 4, 30, 25);
    demonstratePolymorphismByReference(pte);

    return 0;
}
