// Person.cpp
#include "Person.h"

Person::Person(std::string name, int age) : name(name), age(age) {}

void Person::showInfo() const {
    std::cout << "Name: " << name << "\nAge: " << age << std::endl;
}

Person::~Person() {}
