#include <iostream>
#include <memory>
#include <limits>
#include "Race.h"
#include "GroundTransport.h"
#include "AirTransport.h"

// Для локализации
#include <locale>

int main() {
    // Устанавливаем локаль по умолчанию для корректного вывода русского текста
    std::locale::global(std::locale(""));

    while (true) {
        std::cout << "Добро пожаловать в гоночный симулятор!\n";
        std::cout << "1. Гонка для наземного транспорта\n";
        std::cout << "2. Гонка для воздушного транспорта\n";
        std::cout << "3. Гонка для наземного и воздушного транспорта\n";
        std::cout << "Выберите тип гонки (0 для выхода): ";

        int raceTypeInput;
        std::cin >> raceTypeInput;

        if (raceTypeInput == 0) {
            break;  // Выход из программы
        }

        // Проверка корректности ввода
        if (raceTypeInput < 1 || raceTypeInput > 3) {
            std::cout << "Некорректный выбор. Пожалуйста, выберите 1, 2 или 3.\n";
            continue;
        }

        RaceType raceType = static_cast<RaceType>(raceTypeInput);

        std::cout << "Укажите длину дистанции (должна быть положительна): ";
        double distance;
        std::cin >> distance;

        while (distance <= 0) {
            std::cout << "Дистанция должна быть положительной. Повторите ввод: ";
            std::cin >> distance;
        }

        Race race(distance, raceType);

        // Регистрация транспортных средств
        while (true) {
            std::cout << "\nЗарегистрированные транспортные средства: " << race.getRegisteredTransports() << "\n";
            std::cout << "Доступные транспортные средства:\n";

            int optionNumber = 1;
            std::vector<std::pair<int, std::string>> transportOptions;

            // Добавляем опции для наземного транспорта
            if (raceType == GroundRace || raceType == MixedRace) {
                std::cout << optionNumber << ". Ботинки-вездеходы\n";
                transportOptions.emplace_back(optionNumber++, "BootsAllTerrain");
                std::cout << optionNumber << ". Верблюд\n";
                transportOptions.emplace_back(optionNumber++, "Camel");
                std::cout << optionNumber << ". Кентавр\n";
                transportOptions.emplace_back(optionNumber++, "Centaur");
                std::cout << optionNumber << ". Верблюд-быстроход\n";
                transportOptions.emplace_back(optionNumber++, "FastCamel");
            }

            // Добавляем опции для воздушного транспорта
            if (raceType == AirRace || raceType == MixedRace) {
                std::cout << optionNumber << ". Метла\n";
                transportOptions.emplace_back(optionNumber++, "Broom");
                std::cout << optionNumber << ". Орёл\n";
                transportOptions.emplace_back(optionNumber++, "Eagle");
                std::cout << optionNumber << ". Ковёр-самолёт\n";
                transportOptions.emplace_back(optionNumber++, "MagicCarpet");
            }

            std::cout << "0. Закончить регистрацию\n";
            std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

            int choice;
            std::cin >> choice;

            if (choice == 0) {
                break;  // Выходим из цикла регистрации
            }

            if (choice < 1 || choice >= optionNumber) {
                std::cout << "Некорректный выбор. Повторите ввод.\n";
                continue;
            }

            std::string transportKey = transportOptions[choice - 1].second;
            std::unique_ptr<Transport> transport;

            if (transportKey == "BootsAllTerrain") {
                transport = std::make_unique<BootsAllTerrain>();
            } else if (transportKey == "Camel") {
                transport = std::make_unique<Camel>();
            } else if (transportKey == "Centaur") {
                transport = std::make_unique<Centaur>();
            } else if (transportKey == "FastCamel") {
                transport = std::make_unique<FastCamel>();
            } else if (transportKey == "Broom") {
                transport = std::make_unique<Broom>();
            } else if (transportKey == "Eagle") {
                transport = std::make_unique<Eagle>();
            } else if (transportKey == "MagicCarpet") {
                transport = std::make_unique<MagicCarpet>();
            }

            if (transport) {
                if (race.isTransportRegistered(transport->getName())) {
                    std::cout << transport->getName() << " уже зарегистрирован!\n";
                } else {
                    race.registerTransport(std::move(transport));
                    std::cout << "Транспортное средство зарегистрировано!\n";
                }
            }
        }

        if (race.getRegisteredCount() < 2) {
            std::cout << "Должно быть зарегистрировано хотя бы два транспортных средства для начала гонки.\n";
            continue;  // Начинаем заново
        }

        // Начало гонки
        auto results = race.startRace();

        // Вывод результатов
        std::cout << "\nРезультаты гонки:\n";
        int position = 1;
        for (const auto& result : results) {
            std::cout << position++ << ". " << result.first << ". Время: " << result.second << " ч\n";
        }

        // Предложение провести ещё одну гонку
        std::cout << "\n1. Провести ещё одну гонку\n2. Выйти\nВыберите действие: ";
        int nextAction;
        std::cin >> nextAction;

        if (nextAction != 1) {
            break;  // Выходим из программы
        }
    }

    std::cout << "Спасибо за использование гоночного симулятора!\n";
    return 0;
}