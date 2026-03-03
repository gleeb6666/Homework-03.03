#include "Car.h"
#include <iostream>

Route get_route() {
    Route r;
    std::cout << "Enter route length (in km): ";
    std::cin >> r.length;
    std::cout << "Enter time (in h): ";
    std::cin >> r.time;
    std::cout << "Enter number of people: ";
    std::cin >> r.people;
    std::cout << "Enter weather conditions (sun, rain, or snow): ";
    std::cin >> r.weather;
    return r;
}

Car::Car(const std::string& name, double speed, int seats, TireType tires) {
    this->name = name;
    this->speed = speed;
    this->seats = seats;
    this->tires = tires;
}

bool Car::setSpeed(double speed) {
    if (speed < 10 || speed > 200) return false;
    this->speed = speed;
    return true;
}

bool Car::setSeats(int seats) {
    if (seats < 1 || seats > 8) return false;
    this->seats = seats;
    return true;
}

void Car::setTires(TireType tires) {
    this->tires = tires;
}

Car::TravelResult Car::canTravel(const Route& r) const {
    if (r.people > seats)
        return ROUTE_NO_SPACE;
    if (r.length / r.time > speed)
        return ROUTE_NO_TIME;
    if (r.weather == "snow" && tires != WINTER && tires != ALL_SEASON)
        return ROUTE_BAD_WEATHER;
    if (r.weather == "rain" && tires != RAIN && tires != ALL_SEASON)
        return ROUTE_BAD_WEATHER;
    return ROUTE_OK;
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    std::string tireStr;
    if (car.tires == Car::SUMMER) tireStr = "summer tires";
    else if (car.tires == Car::RAIN) tireStr = "rain tires";
    else if (car.tires == Car::WINTER) tireStr = "winter tires";
    else tireStr = "all-season tires";

    os << "Car: \"" << car.name << "\" with speed of " << car.speed
        << " km/h, " << car.seats << " seats and " << tireStr << ".";
    return os;
}