#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age);
    void showInfoStatic() const;
    virtual void showInfo() const;
    virtual ~Person() {}
};