#pragma once
#include <string>

class Rectangle {
private:
    double a;
    double b;

public:
    Rectangle(double a, double b);
    std::string getRotations(double w, double h) const;
};
