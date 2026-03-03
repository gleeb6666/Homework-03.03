#include <iostream>
#include "Car.h"

int main() {
    Car car("BMW", 100, 2, Car::WINTER);

    std::cout << car << std::endl;

    Route r = get_route();
    int res = car.canTravel(r);

    if (res == Car::ROUTE_OK) {
        std::cout << "Car can travel the assigned route." << std::endl;
    }
    else if (res == Car::ROUTE_NO_SPACE) {
        std::cout << "There is not enough space in the car." << std::endl;
    }
    else if (res == Car::ROUTE_NO_TIME) {
        std::cout << "The car is not fast enough for this route." << std::endl;
    }
    else if (res == Car::ROUTE_BAD_WEATHER) {
        std::cout << "Wrong tires for current weather conditions." << std::endl;
    }

    return 0;
}
