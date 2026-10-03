#define _CRT_SECURE_NO_WARNINGS
#include "CompanyManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void CompanyManager::printTable(const Company* arr, int size, const char* title) {
    std::cout << "\n=======================================================================\n";
    std::cout << title << "\n";
    std::cout << "=======================================================================\n";
    std::cout << "| Фірма        | Кільк. продуктів     | Річний об'єм продажу($)| Частина ринку (%)|\n";
    std::cout << "-----------------------------------------------------------------------\n";

    for (int i = 0; i < size; ++i) {
        (arr + i)->show();
    }
    std::cout << "-----------------------------------------------------------------------\n";
}

Company* CompanyManager::loadFromFile(const char* filename, int& size) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Помилка відкриття файлу " << filename << "!\n";
        size = 0;
        return nullptr;
    }

    file >> size;
    Company* arr = new Company[size];

    for (int i = 0; i < size; ++i) {
        char name[50];
        int count;
        double sales, share;

        file >> name >> count >> sales >> share;
        (arr + i)->setName(name);
        (arr + i)->setProductCount(count);
        (arr + i)->setAnnualSales(sales);
        (arr + i)->setMarketShare(share);
    }

    file.close();
    return arr;
}

Company* CompanyManager::inputFromConsole(int& size) {
    std::cout << "Введіть кількість фірм для введення з клавіатури: ";
    std::cin >> size;

    Company* arr = new Company[size];

    for (int i = 0; i < size; ++i) {
        char name[50];
        int count;
        double sales, share;

        std::cout << "\nФірма #" << (i + 1) << ":\n";
        std::cout << "Назва: ";
        std::cin >> name;
        std::cout << "Кількість продуктів: ";
        std::cin >> count;
        std::cout << "Річний об'єм продажу ($): ";
        std::cin >> sales;
        std::cout << "Частина ринку (%): ";
        std::cin >> share;
        *(arr + i) = Company(name, count, sales, share);
    }

    return arr;
}

Company* CompanyManager::createCopyArray(const Company* src, int size) {
    if (!src || size <= 0) return nullptr;

    Company* copyArr = new Company[size];
    for (int i = 0; i < size; ++i) {
        *(copyArr + i) = Company(*(src + i));
    }
    return copyArr;
}