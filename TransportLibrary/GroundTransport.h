#ifndef GROUNDTRANSPORT_H
#define GROUNDTRANSPORT_H

#include "Transport.h"

class GroundTransport : public Transport {
protected:
    double moveTime;  // Время движения до отдыха

public:
    GroundTransport(double speed, double moveTime);
    double calculateTime(double distance) const override;
    virtual double calculateRestDuration(int restCount) const = 0;  // Расчёт времени отдыха
};

// Классы-наследники

class Camel : public GroundTransport {
public:
    Camel();
    double calculateRestDuration(int restCount) const override;
    std::string getName() const override;
};

class FastCamel : public GroundTransport {
public:
    FastCamel();
    double calculateRestDuration(int restCount) const override;
    std::string getName() const override;
};

class Centaur : public GroundTransport {
public:
    Centaur();
    double calculateRestDuration(int restCount) const override;
    std::string getName() const override;
};

class BootsAllTerrain : public GroundTransport {
public:
    BootsAllTerrain();
    double calculateRestDuration(int restCount) const override;
    std::string getName() const override;
};

#endif // GROUNDTRANSPORT_H
