#include <iostream>
#include <windows.h>
#include "Company.h"
#include "Functions.h"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Company* arr1 = nullptr;
    int size1 = 0;
    Company* arr2 = nullptr;
    int size2 = 0;
    Company* arr3 = nullptr;
    int size3 = 0;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n--- МЕНЮ ---\n";
        std::cout << "1. Читати з файлу\n";
        std::cout << "2. Ввести з клавіатури\n";
        std::cout << "3. Скопіювати масив\n";
        std::cout << "4. Змінити об'єм продажів\n";
        std::cout << "5. Показати всі масиви\n";
        std::cout << "0. Вихід\n";
        std::cout << "Вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (arr1) delete[] arr1;
            arr1 = loadFromFile("data.txt", size1);
            if (arr1) std::cout << "Дані зчитано!\n";
            break;

        case 2:
            if (arr2) delete[] arr2;
            arr2 = inputFromConsole(size2);
            break;

        case 3:
            if (!arr1 && !arr2) {
                std::cout << "Немає даних для копіювання!\n";
            }
            else {
                if (arr3) delete[] arr3;
                const Company* src = arr1 ? arr1 : arr2;
                size3 = arr1 ? size1 : size2;
                arr3 = copyArray(src, size3);
                std::cout << "Скопійовано!\n";
            }
            break;


        case 4:
            if (!arr1) {
                std::cout << "Спочатку завантажте перший масив!\n";
                break;
            }
            int idx;
            std::cout << "Індекс об'єкта (0 - " << size1 - 1 << "): ";
            std::cin >> idx;

            if (idx >= 0 && idx < size1) {
                double newSales;
                std::cout << "Новий об'єм продажів: ";
                std::cin >> newSales;
                (arr1 + idx)->setSales(newSales);
                std::cout << "Змінено!\n";
            }
            else {
                std::cout << "Невірний індекс!\n";
            }
            break;



        case 5:
            if (arr1) printArray(arr1, size1, "Масив 1 (з файлу)");
            else std::cout << "\nМасив 1 порожній.\n";

            if (arr2) printArray(arr2, size2, "Масив 2 (з консолі)");
            else std::cout << "\nМасив 2 порожній.\n";

            if (arr3) printArray(arr3, size3, "Масив 3 (копія)");
            else std::cout << "\nМасив 3 порожній.\n";
            break;

        case 0:
            std::cout << "Вихід з програми.\n";
            break;

        default:
            std::cout << "Невірний вибір!\n";
        }
    }

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}