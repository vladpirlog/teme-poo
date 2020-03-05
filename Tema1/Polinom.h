#ifndef TEMA1_POLINOM_H
#define TEMA1_POLINOM_H

#include <iostream>

class Polinom
{
    int grade;
    double *coefficients;

public:
    Polinom();
    Polinom(int, double *);
    Polinom(const Polinom &);
    ~Polinom();

    double value(int);
    Polinom operator+(Polinom);
    Polinom operator-(Polinom);
    Polinom operator*(Polinom);

    friend std::istream &operator>>(std::istream &, Polinom &);
    friend std::ostream &operator<<(std::ostream &, Polinom &);
};

#endif