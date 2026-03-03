#include "Rectangle.h"

Rectangle::Rectangle(double a, double b) {
    this->a = a;
    this->b = b;
}

std::string Rectangle::getRotations(double w, double h) const {
    if (w <= a && h <= b) return ".";
    if (w <= b && h <= a) return "x";
    if (h <= a && w <= b) return "y";

    if (w <= a && h <= a) return "y";
    if (h <= a && w <= a) return "x";

    double w1 = w, h1 = h;

    // try x then y
    double after_x_w = h1, after_x_h = w1;
    if (after_x_w <= a && after_x_h <= b) return "x";
    if (after_x_h <= a && after_x_w <= b) return "xy";

    // try y then x
    double after_y_w = h1, after_y_h = w1;
    if (after_y_h <= a && after_y_w <= b) return "y";
    if (after_y_w <= a && after_y_h <= b) return "yx";

    return "";
}