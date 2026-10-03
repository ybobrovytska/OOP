#ifndef COMPANY_H
#define COMPANY_H

class Company {
private:
    char name[50];
    int count;
    double sales;
    double share;

public:
    Company();
    Company(const char* n, int c, double s, double sh);
    Company(const Company& other);

    const char* getName() const;
    int getCount() const;
    double getSales() const;
    double getShare() const;

    void setName(const char* n);
    void setCount(int c);
    void setSales(double s);
    void setShare(double sh);

    void show() const;
};

#endif