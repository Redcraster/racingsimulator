#include "GroundTransport.h"
#include <cmath>  // Для функции fmod

GroundTransport::GroundTransport(double speed, double moveTime)
    : Transport(speed), moveTime(moveTime) {}

double GroundTransport::calculateTime(double distance) const {
    // Время движения без учёта отдыхов
    double travelTime = distance / speed;

    // Количество полных периодов движения до отдыха
    int fullMovePeriods = static_cast<int>(distance / (speed * moveTime));

    // Проверка, нужно ли уменьшить количество отдыхов
    if (fmod(distance, speed * moveTime) == 0 && fullMovePeriods > 0) {
        fullMovePeriods -= 1;
    }

    // Общее время отдыха
    double totalRestTime = 0.0;
    for (int i = 1; i <= fullMovePeriods; ++i) {
        totalRestTime += calculateRestDuration(i);
    }

    // Общее время = время движения + время отдыха
    double totalTime = travelTime + totalRestTime;

    return totalTime;
}

// Реализация класса Camel

Camel::Camel() : GroundTransport(10, 30) {}

double Camel::calculateRestDuration(int restCount) const {
    return (restCount == 1) ? 5 : 8;
}

std::string Camel::getName() const {
    return "Верблюд";
}

// Реализация класса FastCamel

FastCamel::FastCamel() : GroundTransport(40, 10) {}

double FastCamel::calculateRestDuration(int restCount) const {
    if (restCount == 1) return 5;
    if (restCount == 2) return 6.5;
    return 8;
}

std::string FastCamel::getName() const {
    return "Верблюд-быстроход";
}

// Реализация класса Centaur

Centaur::Centaur() : GroundTransport(15, 8) {}

double Centaur::calculateRestDuration(int restCount) const {
    return 2;
}

std::string Centaur::getName() const {
    return "Кентавр";
}

// Реализация класса BootsAllTerrain

BootsAllTerrain::BootsAllTerrain() : GroundTransport(6, 60) {}

double BootsAllTerrain::calculateRestDuration(int restCount) const {
    return (restCount == 1) ? 10 : 5;
}

std::string BootsAllTerrain::getName() const {
    return "Ботинки-вездеходы";
}
