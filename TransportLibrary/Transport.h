#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>

class Transport {
protected:
    double speed;  // Скорость транспортного средства

public:
    Transport(double speed);  // Конструктор
    virtual double calculateTime(double distance) const = 0;  // Чисто виртуальный метод для расчёта времени
    virtual std::string getName() const = 0;  // Получение названия транспортного средства
    virtual ~Transport();  // Виртуальный деструктор
};

#endif // TRANSPORT_H

