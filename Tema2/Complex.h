#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
    float re, im;

public:
    Complex();
    Complex(float, float);
    Complex(const Complex &);
    ~Complex();

    float getRe();
    float getIm();

    friend std::istream &operator>>(std::istream &, Complex &);
    friend std::ostream &operator<<(std::ostream &, const Complex &);

    void operator=(const Complex &);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
};

#endif //COMPLEX_H
