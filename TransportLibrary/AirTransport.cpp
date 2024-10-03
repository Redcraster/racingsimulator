#include "AirTransport.h"

AirTransport::AirTransport(double speed) : Transport(speed) {}

double AirTransport::calculateTime(double distance) const {
    double reducedDistance = calculateReducedDistance(distance);
    return reducedDistance / speed;
}

// Реализация класса MagicCarpet

MagicCarpet::MagicCarpet() : AirTransport(10) {}

double MagicCarpet::calculateReducedDistance(double distance) const {
    if (distance < 1000) return distance;
    if (distance < 5000) return distance * 0.97;
    if (distance < 10000) return distance * 0.9;
    return distance * 0.95;
}

std::string MagicCarpet::getName() const {
    return "Ковёр-самолёт";
}

// Реализация класса Eagle




Eagle::Eagle() : AirTransport(8) {}

double Eagle::calculateReducedDistance(double distance) const {
    return distance * 0.94;
}

std::string Eagle::getName() const {
    return "Орёл";
}

// Реализация класса Broom

Broom::Broom() : AirTransport(20) {}

double Broom::calculateReducedDistance(double distance) const {
    int thousands = static_cast<int>(distance / 1000);
    double reduction = 1.0 - 0.01 * thousands;
    if (reduction < 0.0) {
        reduction = 0.0;  // Не может быть отрицательным
    }
    return distance * reduction;
}

std::string Broom::getName() const {
    return "Метла";
}