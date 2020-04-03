#ifndef MATRICE_H
#define MATRICE_H

#include "Complex.h"

class Matrice
{
protected:
    Complex **v;

public:
    Matrice();
    Matrice(Complex **);
    Matrice(const Matrice &);
    ~Matrice();

    virtual Complex at(int, int);
    virtual void put(Complex, int, int);

    virtual friend std::istream &operator>>(std::istream &, Matrice &);
    virtual friend std::ostream &operator<<(std::ostream &, const Matrice &);

    virtual void operator=(const Matrice &);
};

#endif // MATRICE_H