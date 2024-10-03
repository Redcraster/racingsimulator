#ifndef AIRTRANSPORT_H
#define AIRTRANSPORT_H

#include "Transport.h"

class AirTransport : public Transport {
public:
    AirTransport(double speed);
    double calculateTime(double distance) const override;
    virtual double calculateReducedDistance(double distance) const = 0;
};

// Классы-наследники

class MagicCarpet : public AirTransport {
public:
    MagicCarpet();
    double calculateReducedDistance(double distance) const override;
    std::string getName() const override;
};

class Eagle : public AirTransport {
public:
    Eagle();
    double calculateReducedDistance(double distance) const override;
    std::string getName() const override;
};

class Broom : public AirTransport {
public:
    Broom();
    double calculateReducedDistance(double distance) const override;
    std::string getName() const override;
};

#endif // AIRTRANSPORT_H
