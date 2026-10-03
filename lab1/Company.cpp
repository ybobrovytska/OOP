#define _CRT_SECURE_NO_WARNINGS
#include "Company.h"
#include <iostream>
#include <cstring>

Company::Company() {
    strcpy(name, "Noname");
    count = 0;
    sales = 0.0;
    share = 0.0;
}

Company::Company(const char* n, int c, double s, double sh) {
    strcpy(name, n);
    count = c;
    sales = s;
    share = sh;
}

Company::Company(const Company& other) {
    strcpy(name, other.name);
    count = other.count;
    sales = other.sales;
    share = other.share;
}

const char* Company::getName() const { return name; }
int Company::getCount() const { return count; }
double Company::getSales() const { return sales; }
double Company::getShare() const { return share; }

void Company::setName(const char* n) { strcpy(name, n); }
void Company::setCount(int c) { count = c; }
void Company::setSales(double s) { sales = s; }
void Company::setShare(double sh) { share = sh; }

void Company::show() const {
    std::cout << name << "\t\t" << count << "\t\t" << sales << "\t\t" << share << "\n";
}