#include "Complex.h"

Complex::Complex()
{
    this->re = 0;
    this->im = 0;
}

Complex::Complex(float re, float im)
{
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex &n)
{
    this->re = n.re;
    this->im = n.im;
}

Complex::~Complex()
{
    std::cout << "Number deleted.\n";
}

float Complex::getRe()
{
    return this->re;
}

float Complex::getIm()
{
    return this->im;
}

void Complex::operator=(const Complex &x)
{
    this->re = x.re;
    this->im = x.im;
}

Complex Complex::operator+(const Complex &x)
{
    Complex c = Complex(this->re + x.re, this->im + x.im);
    return c;
}

Complex Complex::operator-(const Complex &x)
{
    Complex c = Complex(this->re - x.re, this->im - x.im);
    return c;
}

std::istream &operator>>(std::istream &is, Complex &p)
{
    float r, i;
    std::cout << "Enter Re: ";
    is >> r;
    p.re = r;
    std::cout << "Enter Im: ";
    is >> i;
    p.im = i;

    return is;
}

std::ostream &operator<<(std::ostream &, const Complex &p)
{
    std::cout << p.re << "+" << p.im << "j\n";
}
