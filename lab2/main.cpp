#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Firm.h"

void printHeader() {
    std::cout << std::left << std::setw(15) << "Firm"
        << std::setw(12) << "Products"
        << std::setw(20) << "Annual Sales ($)"
        << std::setw(10) << "Share (%)" << "\n";
    std::cout << "---------------------------------------------------------\n";
}

int main() {
    Firm arrayMember[3] = {
        Firm("Oracle", 1, 2488000000.0, 31.1),
        Firm("IBM", 3, 2392000000.0, 29.9),
        Firm("Microsoft", 2, 1048000000.0, 13.1)
    };

    Firm arrayFriend[3];
    arrayFriend[0] = arrayMember[0];
    arrayFriend[1] = arrayMember[1];
    arrayFriend[2] = arrayMember[2];

    int choice = 0;
    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Show initial data\n";
        std::cout << "2. Test operators (==, +, =)\n";
        std::cout << "3. Test friend operators via function call\n";
        std::cout << "4. Test operator [] (length of char*)\n";
        std::cout << "5. Test operator () (re-initialization)\n";
        std::cout << "6. Test stream operators (<<, >>)\n";
        std::cout << "0. Exit\n";
        std::cout << "Select option: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "\nInitial Table:\n";
            printHeader();
            for (int i = 0; i < 3; i++) {
                arrayMember[i].show();
            }
            break;
        }
        case 2: {
            std::cout << "\nTesting operators:\n";
            if (arrayMember[0] == arrayMember[1]) {
                std::cout << "Firm 0 and Firm 1 are equal\n";
            }
            else {
                std::cout << "Firm 0 and Firm 1 are NOT equal\n";
            }

            Firm combinedMember = arrayMember[0] + arrayMember[2];
            std::cout << "\nCombined Firm (+):\n";
            printHeader();
            combinedMember.show();
            break;
        }
        case 3: {
            std::cout << "\nTesting friend operators explicitly:\n";
            if (operator==(arrayFriend[0], arrayFriend[0])) {
                std::cout << "Firm 0 and Firm 0 are equal\n";
            }

            Firm combinedFriend = operator+(arrayFriend[1], arrayFriend[2]);
            std::cout << "\nCombined Firm (operator+()):\n";
            printHeader();
            combinedFriend.show();
            break;
        }
        case 4: {
            char testStr[100];
            std::cout << "\nEnter string to measure length via operator []: ";
            std::cin >> testStr;
            int length = arrayMember[0][testStr];
            std::cout << "Length of '" << testStr << "' is: " << length << "\n";
            break;
        }
        case 5: {
            std::cout << "\nRe-initializing Firm 0 using operator ():\n";
            arrayMember[0]("Google", 5, 5000000000.0, 45.0);
            printHeader();
            arrayMember[0].show();
            break;
        }
        case 6: {
            std::cout << "\nTesting << operator on Firm 1:\n";
            std::cout << arrayMember[1] << "\n";

            std::cout << "\nEnter new Firm data (Name Products Sales Share): ";
            Firm temp;
            std::cin >> temp;
            std::cout << "\nOutput via << operator:\n";
            std::cout << temp << "\n";
            break;
        }
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}