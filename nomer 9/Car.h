#pragma once
#include <string>

class Route {
public:
    double length;
    double time;
    int people;
    std::string weather;
};

Route get_route();

class Car {
public:
    enum TireType { SUMMER, RAIN, WINTER, ALL_SEASON };
    enum TravelResult { ROUTE_OK, ROUTE_NO_SPACE, ROUTE_NO_TIME, ROUTE_BAD_WEATHER };

private:
    std::string name;
    double speed;
    int seats;
    TireType tires;

public:
    Car(const std::string& name, double speed, int seats, TireType tires);

    bool setSpeed(double speed);
    bool setSeats(int seats);
    void setTires(TireType tires);

    TravelResult canTravel(const Route& r) const;

    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};