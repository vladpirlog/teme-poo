#include "Complex.h"
#include "NotAFloat.h"
#include <string>

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
    // std::cout << "Number deleted.\n";
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
    return Complex(this->re + x.re, this->im + x.im);
}

Complex Complex::operator-(const Complex &x)
{
    return Complex(this->re - x.re, this->im - x.im);
}

Complex Complex::operator*(const Complex &x)
{
    return Complex(this->re * x.re - this->im * x.im, this->re * x.im + this->im * x.re);
}

Complex Complex::operator/(const Complex &x)
{
    if (x.re == 0 && x.im == 0)
    {
        return Complex(99999, 99999);
    }
    return Complex((this->re * x.re + this->im * x.im) / (x.re * x.re + x.im * x.im),
                   (this->im * x.re - this->re * x.im) / (x.re * x.re + x.im * x.im));
}

bool Complex::operator==(const Complex &x)
{
    return this->re == x.re && this->im == x.im;
}

bool Complex::operator!=(const Complex &x)
{
    return this->re != x.re || this->im != x.im;
}

std::istream &operator>>(std::istream &is, Complex &p)
{
    try
    {
        std::string r, i;
        std::cout << "Enter Re: ";
        is >> r;
        p.re = std::stof(r);
        std::cout << "Enter Im: ";
        is >> i;
        p.im = std::stof(i);
        return is;
    }
    catch (const std::invalid_argument &e)
    {
        throw(NotAFloat());
    }
}

std::ostream &operator<<(std::ostream &os, const Complex &p)
{
    os << std::setprecision(4);
    if (p.im >= 0)
        os << p.re << "+" << p.im << "j";
    else
        os << p.re << "-" << -p.im << "j";
    return os;
}
