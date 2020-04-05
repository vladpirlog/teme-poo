#ifndef MATRICE_PATRATICA_H
#define MATRICE_PATRATICA_H

#include "Matrice.h"

class Matrice_patratica : private Matrice
{
private:
    int dim;

public:
    Matrice_patratica();
    Matrice_patratica(int, Complex**);
    Matrice_patratica(const Matrice_patratica &);

    Complex at(int, int);
    void put(Complex, int, int);
    Complex calcDeterminant() const;
    bool isDiagonal();

    friend std::istream &operator>>(std::istream &, Matrice_patratica &);
    friend std::ostream &operator<<(std::ostream &, const Matrice_patratica &);
    void operator=(const Matrice_patratica &);
};

#endif // MATRICE_PATRATICA_H