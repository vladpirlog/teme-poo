#include "Matrice.h"

Matrice::Matrice()
{
    this->v = new Complex *[40];
    for (int i = 0; i < 40; ++i)
    {
        (this->v)[i] = new Complex[40];
    }
}

Matrice::Matrice(int lin, int col, Complex **v)
{
    for (int i = 0; i < lin; ++i)
    {
        for (int j = 0; j < col; j++)
        {
            (this->v)[i][j] = v[i][j];
        }
    }
}

Matrice::Matrice(const Matrice &m)
{
    for (int i = 0; i < 40; ++i)
    {
        for (int j = 0; j < 40; j++)
        {
            (this->v)[i][j] = (m.v)[i][j];
        }
    }
}

Matrice::~Matrice()
{
    for (int i = 0; i < 100; ++i)
    {
        delete[](this->v)[i];
    }
}