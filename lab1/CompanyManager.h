#ifndef COMPANY_MANAGER_H
#define COMPANY_MANAGER_H

#include "Company.h"
class CompanyManager {
public:
    static void printTable(const Company* arr, int size, const char* title);

    static Company* loadFromFile(const char* filename, int& size);

    static Company* inputFromConsole(int& size);

    static Company* createCopyArray(const Company* src, int size);
};

#endif