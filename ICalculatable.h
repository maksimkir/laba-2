// ICalculatable.h
#ifndef ICALCULATABLE_H
#define ICALCULATABLE_H

class ICalculatable {
public:
    virtual double calculateSalary() const = 0;
    virtual ~ICalculatable() = default;
};

#endif
