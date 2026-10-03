#ifndef FIRM_H
#define FIRM_H
#include <iostream>

class Firm {
private:
    char* name;
    int productsCount;
    double annualSales;
    double marketShare;

public:
    Firm();
    Firm(const char* nameVal, int countVal, double salesVal, double shareVal);
    Firm(const Firm& other);
    ~Firm();

    const char* getName() const;
    int getProductsCount() const;
    double getAnnualSales() const;
    double getMarketShare() const;
    void setName(const char* nameVal);
    void setProductsCount(int countVal);
    void setAnnualSales(double salesVal);
    void setMarketShare(double shareVal);

    void show() const;

    Firm& operator=(const Firm& other);
    friend bool operator==(const Firm& f1, const Firm& f2);
    friend Firm operator+(const Firm& f1, const Firm& f2);

    int operator[](const char* str) const;
    void operator()(const char* nameVal, int countVal, double salesVal, double shareVal);

    friend std::ostream& operator<<(std::ostream& os, const Firm& firm);
    friend std::istream& operator>>(std::istream& is, Firm& firm);
};
#endif