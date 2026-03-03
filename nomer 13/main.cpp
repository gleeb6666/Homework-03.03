#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle rect(4, 2);

    double w, h;
    std::cout << "Enter ingot width: ";
    std::cin >> w;
    std::cout << "Enter ingot height: ";
    std::cin >> h;

    std::string result = rect.getRotations(w, h);

    if (result.empty()) {
        std::cout << "Cannot fit the ingot into the frame." << std::endl;
    }
    else if (result == ".") {
        std::cout << "No rotations needed." << std::endl;
    }
    else {
        std::cout << "Rotations needed: " << result << std::endl;
    }

    return 0;
}
