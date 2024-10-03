#ifndef RACE_H
#define RACE_H

#include <vector>
#include <memory>
#include <string>
#include "Transport.h"

enum RaceType {
    GroundRace = 1,
    AirRace = 2,
    MixedRace = 3
};

class Race {
private:
    double distance;
    RaceType raceType;
    std::vector<std::unique_ptr<Transport>> transports;

public:
    Race(double distance, RaceType raceType);
    void registerTransport(std::unique_ptr<Transport> t);
    bool isTransportRegistered(const std::string& name) const;
    bool isCorrectTransportType(const Transport& t) const;
    std::vector<std::pair<std::string, double>> startRace() const;
    int getRegisteredCount() const;
    std::string getRegisteredTransports() const;
};

#endif // RACE_H
