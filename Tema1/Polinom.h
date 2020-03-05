#ifndef TEMA1_POLINOM_H
#define TEMA1_POLINOM_H

#include <iostream>

class Polinom
{
    int grade;
    double *coefficients;

public:
    Polinom();
    Polinom(int, double*);
    Polinom(const Polinom&);
    ~Polinom();

    double value(int x);
    Polinom operator+(Polinom p);
    Polinom operator-(Polinom p);
    Polinom operator*(Polinom p);

    friend std::istream& operator>>(std::istream&, Polinom&);
    friend std::ostream& operator<<(std::ostream&, Polinom&);
};

#endif