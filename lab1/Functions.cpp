#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include <iostream>
#include <fstream>

void printArray(const Company* arr, int size, const char* title) {
    std::cout << "\n=== " << title << " ===\n";
    std::cout << "Фірма\t\tПродукти\tПродажі($)\tЧастка(%)\n";
    std::cout << "--------------------------------------------------------\n";

    for (int i = 0; i < size; ++i) {
        const Company* ptr = arr + i;
        ptr->show();
    }
    std::cout << "--------------------------------------------------------\n";
}

Company* loadFromFile(const char* filename, int& size) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Помилка відкриття файлу!\n";
        size = 0;
        return nullptr;
    }

    file >> size;
    Company* arr = new Company[size];

    for (int i = 0; i < size; ++i) {
        char n[50];
        int c;
        double s, sh;

        file >> n >> c >> s >> sh;

        Company* ptr = arr + i;
        ptr->setName(n);
        ptr->setCount(c);
        ptr->setSales(s);
        ptr->setShare(sh);
    }

    file.close();
    return arr;
}

Company* inputFromConsole(int& size) {
    std::cout << "Введіть кількість фірм: ";
    std::cin >> size;

    Company* arr = new Company[size];

    for (int i = 0; i < size; ++i) {
        char n[50];
        int c;
        double s, sh;

        std::cout << "\nФірма #" << (i + 1) << ":\n";
        std::cout << "Назва: ";
        std::cin >> n;
        std::cout << "Кількість продуктів: ";
        std::cin >> c;
        std::cout << "Об'єм продажу: ";
        std::cin >> s;
        std::cout << "Частка ринку (%): ";
        std::cin >> sh;

        *(arr + i) = Company(n, c, s, sh);
    }

    return arr;
}

Company* copyArray(const Company* src, int size) {
    if (!src || size <= 0) return nullptr;

    Company* res = new Company[size];
    for (int i = 0; i < size; ++i) {
        *(res + i) = Company(*(src + i));
    }
    return res;
}