#include "Matrice.h"
#include "EmptyMatrix.h"

#define MATRIX_SIZE 40

Matrice::Matrice()
{
    this->v = new Complex *[MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        (this->v)[i] = new Complex[MATRIX_SIZE];
    }
}

Matrice::Matrice(int lin, int col, Complex **v) : Matrice::Matrice()
{
    if (lin <= 0 || col <= 0)
    {
        throw(EmptyMatrix());
    }
    for (int i = 0; i < lin; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            (this->v)[i][j] = v[i][j];
        }
    }
}

Matrice::Matrice(const Matrice &m) : Matrice::Matrice()
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        for (int j = 0; j < MATRIX_SIZE; ++j)
        {
            (this->v)[i][j] = (m.v)[i][j];
        }
    }
}

Matrice::~Matrice()
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        delete[](this->v)[i];
    }
    delete[](this->v);
}
