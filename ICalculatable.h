#pragma once

class ICalculatable {
public:

    virtual double calculateSalary() const = 0;
    virtual ~ICalculatable() = default;
};
