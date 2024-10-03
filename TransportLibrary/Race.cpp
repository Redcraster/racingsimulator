#include "Race.h"
#include "GroundTransport.h"
#include "AirTransport.h"
#include <algorithm>

Race::Race(double distance, RaceType raceType) : distance(distance), raceType(raceType) {}

void Race::registerTransport(std::unique_ptr<Transport> t) {
    transports.push_back(std::move(t));
}

bool Race::isTransportRegistered(const std::string& name) const {
    for (const auto& transport : transports) {
        if (transport->getName() == name) {
            return true;
        }
    }
    return false;
}

bool Race::isCorrectTransportType(const Transport& t) const {
    if (raceType == GroundRace) {
        return dynamic_cast<const GroundTransport*>(&t) != nullptr;
    }
    if (raceType == AirRace) {
        return dynamic_cast<const AirTransport*>(&t) != nullptr;
    }
    return true;  // Для смешанной гонки подходят все виды транспорта
}

std::vector<std::pair<std::string, double>> Race::startRace() const {
    std::vector<std::pair<std::string, double>> results;
    for (const auto& transport : transports) {
        double time = transport->calculateTime(distance);
        results.emplace_back(transport->getName(), time);
    }
    std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    return results;
}

int Race::getRegisteredCount() const {
    return transports.size();
}

std::string Race::getRegisteredTransports() const {
    std::string list;
    for (const auto& transport : transports) {
        if (!list.empty()) list += ", ";
        list += transport->getName();
    }
    return list;
}