#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Company.h"

void printArray(const Company* arr, int size, const char* title);
Company* loadFromFile(const char* filename, int& size);
Company* inputFromConsole(int& size);
Company* copyArray(const Company* src, int size);

#endif