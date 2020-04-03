#include "Matrice_oarecare.h"

Matrice_oarecare::Matrice_oarecare() : Matrice(){};

Matrice_oarecare::Matrice_oarecare(int lin, int col, Complex **v) : Matrice(lin, col, v){};

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare &m) : Matrice(m){};

Complex Matrice_oarecare::at(int x, int y)
{
    if (0 <= x && x < this->lin && 0 <= y && y < this->col)
        return (this->v)[x][y];
    return Complex(-999, -999);
}

void Matrice_oarecare::put(Complex value, int x, int y)
{
    if (0 <= x && x < this->lin && 0 <= y && y < this->col)
        (this->v)[x][y] = value;
}

std::istream &operator>>(std::istream &is, Matrice_oarecare &m)
{
    std::cout << "Enter number of lines:\n";
    is >> m.lin;
    std::cout << "Enter number of columns:\n";
    is >> m.col;

    for (int i = 0; i < m.lin; ++i)
    {
        for (int j = 0; j < m.col; j++)
        {
            std::cout << "m[" << i << "][" << j << "] =\n";
            is >> (m.v)[i][j];
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Matrice_oarecare &m)
{
    for (int i = 0; i < m.lin; ++i)
    {
        for (int j = 0; j < m.col; ++j)
        {
            os << (m.v)[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

void Matrice_oarecare::operator=(const Matrice_oarecare &m)
{
    for (int i = 0; i < m.lin; ++i)
    {
        for (int j = 0; j < m.col; j++)
        {
            (this->v)[i][j] = (m.v)[i][j];
        }
    }
}
