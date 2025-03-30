#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string name, int age);
    virtual void showInfo() const;
    virtual ~Person();
};

#endif // PERSON_H