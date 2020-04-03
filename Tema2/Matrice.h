#ifndef MATRICE_H
#define MATRICE_H

#include "Complex.h"

class Matrice
{
protected:
    Complex **v;

public:
    Matrice();
    Matrice(int, int, Complex **);
    ~Matrice();

    virtual Complex at(int, int) = 0;
    virtual void put(Complex, int, int) = 0;

    virtual bool isDiagonal() = 0;
};

#endif // MATRICE_H