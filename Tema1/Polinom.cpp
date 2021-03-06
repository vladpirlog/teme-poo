#include "Polinom.h"
#include <math.h>

using namespace std;

Polinom::Polinom()
{
    this->coefficients = new double[1];
};

Polinom::Polinom(int grade, double *coefficients)
{
    this->grade = grade;
    this->coefficients = new double[grade + 1];
    for (int i = 0; i <= grade; ++i)
    {
        this->coefficients[i] = coefficients[i];
    }
}

Polinom::Polinom(const Polinom &p)
{
    this->grade = p.grade;
    this->coefficients = new double[grade + 1];
    for (int i = 0; i <= grade; ++i)
    {
        this->coefficients[i] = p.coefficients[i];
    }
}

Polinom::~Polinom()
{
    delete[] coefficients;
    // cout << "Destructor has been called." << endl;
}

double Polinom::value(int x)
{
    double result = 0;
    for (int i = 0; i <= this->grade; ++i)
    {
        result += this->coefficients[i] * pow(x, i);
    }
    return result;
}

Polinom Polinom::operator+(Polinom p)
{
    Polinom res = Polinom();
    if (this->grade > p.grade)
    {
        res.coefficients = new double[this->grade + 1];
        for (int i = 0; i <= this->grade; ++i)
        {
            res.coefficients[i] = this->coefficients[i];
        }

        for (int i = 0; i <= p.grade; ++i)
        {
            res.coefficients[i] += p.coefficients[i];
        }

        for (int j = this->grade; j >= 0; --j)
        {
            if (res.coefficients[j] != 0)
            {
                res.grade = j;
                break;
            }
        }
    }
    else
    {
        res.coefficients = new double[p.grade + 1];
        for (int i = 0; i <= p.grade; ++i)
        {
            res.coefficients[i] = p.coefficients[i];
        }

        for (int i = 0; i <= this->grade; ++i)
        {
            res.coefficients[i] += this->coefficients[i];
        }

        for (int j = p.grade; j >= 0; --j)
        {
            if (res.coefficients[j] != 0)
            {
                res.grade = j;
                break;
            }
        }
    }
    return res;
}

Polinom Polinom::operator-(Polinom p)
{
    Polinom res = Polinom();
    if (this->grade > p.grade)
    {
        res.coefficients = new double[this->grade + 1];
        for (int i = 0; i <= this->grade; ++i)
        {
            res.coefficients[i] = this->coefficients[i];
        }

        for (int i = 0; i <= p.grade; ++i)
        {
            res.coefficients[i] -= p.coefficients[i];
        }

        res.grade = 0;
        for (int j = this->grade; j >= 0; --j)
        {
            if (res.coefficients[j] != 0)
            {
                res.grade = j;
                break;
            }
        }
    }
    else
    {
        res.coefficients = new double[p.grade + 1];
        for (int i = 0; i <= p.grade; ++i)
        {
            res.coefficients[i] = -p.coefficients[i];
        }

        for (int i = 0; i <= this->grade; ++i)
        {
            res.coefficients[i] += this->coefficients[i];
        }

        res.grade = 0;
        for (int j = p.grade; j >= 0; --j)
        {
            if (res.coefficients[j] != 0)
            {
                res.grade = j;
                break;
            }
        }
    }
    return res;
}

Polinom Polinom::operator*(Polinom p)
{
    Polinom res = Polinom();
    res.grade = this->grade + p.grade;
    res.coefficients = new double[this->grade + p.grade + 1];
    for (int i = 0; i <= res.grade; ++i)
    {
        res.coefficients[i] = 0;
    }
    for (int i = 0; i <= this->grade; ++i)
    {
        for (int j = 0; j <= p.grade; ++j)
        {
            res.coefficients[i + j] += this->coefficients[i] * p.coefficients[j];
        }
    }
    return res;
}

istream &operator>>(istream &is, Polinom &p)
{
    int grade;
    cout << "Enter polynom grade: ";
    is >> grade;
    p.grade = grade;
    p.coefficients = new double[grade + 1];
    for (int i = grade; i >= 0; --i)
    {
        cout << "Enter coefficient of x^" << i << ": ";
        is >> p.coefficients[i];
    }
    return is;
}

ostream &operator<<(ostream &os, Polinom &p)
{
    os << "Grade: " << p.grade << "\nP(x) = ";

    for (int i = p.grade; i >= 1; --i)
    {
        if (p.coefficients[i] > 0)
        {
            os << " + " << p.coefficients[i] << " * x^" << i;
        }
        else if (p.coefficients[i] < 0)
        {
            os << " - " << -p.coefficients[i] << " * x^" << i;
        }
    }

    if (p.coefficients[0] > 0)
    {
        os << " + " << p.coefficients[0] << endl;
    }
    else if (p.coefficients[0] < 0)
    {
        os << " - " << -p.coefficients[0] << endl;
    }
    else
    {
        os << endl;
    }
    return os;
}
