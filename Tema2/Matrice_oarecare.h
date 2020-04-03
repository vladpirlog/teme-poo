#ifndef MATRICE_OARECARE_H
#define MATRICE_OARECARE_H

#include "Matrice.h"

class Matrice_oarecare : private Matrice
{
private:
    int lin, col;

public:
    Matrice_oarecare();
    Matrice_oarecare(int, int, Complex**);
    Matrice_oarecare(const Matrice_oarecare &);

    Complex at(int, int);
    void put(Complex, int, int);
    bool isDiagonal();

    friend std::istream &operator>>(std::istream &, Matrice_oarecare &);
    friend std::ostream &operator<<(std::ostream &, const Matrice_oarecare &);
    void operator=(const Matrice_oarecare &);
};

#endif // MATRICE_OARECARE_H