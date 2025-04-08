#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string name, int age) : name(name), age(age) {}

void Person::showInfoStatic() const {
    cout << "[STATIC] Name: " << name << ", Age: " << age << endl;
}

void Person::showInfo() const {
    cout << "Name: " << name << ", Age: " << age << endl;
}

Person::~Person() {}