#define _CRT_SECURE_NO_WARNINGS
#include "Firm.h"
#include <cstring>
#include <iomanip>

Firm::Firm() {
    name = new char[8];
    strcpy(name, "Unknown");
    productsCount = 0;
    annualSales = 0.0;
    marketShare = 0.0;
}

Firm::Firm(const char* nameVal, int countVal, double salesVal, double shareVal) {
    if (nameVal) {
        name = new char[strlen(nameVal) + 1];
        strcpy(name, nameVal);
    }
    else {
        name = new char[8];
        strcpy(name, "Unknown");
    }
    productsCount = countVal;
    annualSales = salesVal;
    marketShare = shareVal;
}

Firm::Firm(const Firm& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    productsCount = other.productsCount;
    annualSales = other.annualSales;
    marketShare = other.marketShare;
}

Firm::~Firm() {
    delete[] name;
}

const char* Firm::getName() const { return name; }
int Firm::getProductsCount() const { return productsCount; }
double Firm::getAnnualSales() const { return annualSales; }
double Firm::getMarketShare() const { return marketShare; }

void Firm::setName(const char* nameVal) {
    if (nameVal) {
        delete[] name;
        name = new char[strlen(nameVal) + 1];
        strcpy(name, nameVal);
    }
}

void Firm::setProductsCount(int countVal) { productsCount = countVal; }
void Firm::setAnnualSales(double salesVal) { annualSales = salesVal; }
void Firm::setMarketShare(double shareVal) { marketShare = shareVal; }

void Firm::show() const {
    std::cout << std::left << std::setw(15) << name
        << std::setw(12) << productsCount
        << std::setw(20) << std::fixed << std::setprecision(0) << annualSales
        << std::setw(10) << std::setprecision(1) << marketShare << "\n";
}

Firm& Firm::operator=(const Firm& other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        productsCount = other.productsCount;
        annualSales = other.annualSales;
        marketShare = other.marketShare;
    }
    return *this;
}

bool operator==(const Firm& f1, const Firm& f2) {
    return (strcmp(f1.name, f2.name) == 0 &&
        f1.productsCount == f2.productsCount &&
        f1.annualSales == f2.annualSales &&
        f1.marketShare == f2.marketShare);
}

Firm operator+(const Firm& f1, const Firm& f2) {
    char newName[256];
    strcpy(newName, f1.name);
    strcat(newName, "+");
    strcat(newName, f2.name);

    return Firm(newName,
        f1.productsCount + f2.productsCount,
        f1.annualSales + f2.annualSales,
        f1.marketShare + f2.marketShare);
}

int Firm::operator[](const char* str) const {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void Firm::operator()(const char* nameVal, int countVal, double salesVal, double shareVal) {
    setName(nameVal);
    productsCount = countVal;
    annualSales = salesVal;
    marketShare = shareVal;
}

std::ostream& operator<<(std::ostream& os, const Firm& firm) {
    os << firm.name << " " << firm.productsCount << " " << firm.annualSales << " " << firm.marketShare;
    return os;
}

std::istream& operator>>(std::istream& is, Firm& firm) {
    char tempName[256];
    is >> tempName >> firm.productsCount >> firm.annualSales >> firm.marketShare;
    firm.setName(tempName);
    return is;
}