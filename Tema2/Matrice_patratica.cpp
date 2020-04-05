#include "Matrice_patratica.h"

Matrice_patratica::Matrice_patratica() : Matrice(){};

Matrice_patratica::Matrice_patratica(int dim) : Matrice(dim, dim) {this->dim = dim;}

Matrice_patratica::Matrice_patratica(int dim, Complex **v) : Matrice(dim, dim, v) { this->dim = dim; };

Matrice_patratica::Matrice_patratica(const Matrice_patratica &m) : Matrice(m) { this->dim = m.dim; };

Complex Matrice_patratica::at(int x, int y)
{
    if (0 <= x && x < this->dim && 0 <= y && y < this->dim)
        return (this->v)[x][y];
    return Complex(-999, -999);
}

void Matrice_patratica::put(Complex value, int x, int y)
{
    if (0 <= x && x < this->dim && 0 <= y && y < this->dim)
        (this->v)[x][y] = value;
}

Complex Matrice_patratica::calcDeterminant() const
{
    // for i in range(nr_necunoscute):
    //     for j in range(i, nr_ecuatii):
    //         if matrix[j][i] != 0:
    //             temp = matrix[i]
    //             matrix[i] = matrix[j]
    //             matrix[j] = temp
    //             break
    //     for j in range(i + 1, nr_ecuatii):
    //         if matrix[i][i] != 0:
    //             rap = matrix[j][i] / matrix[i][i]
    //             for k in range(nr_necunoscute):
    //                 matrix[j][k] = matrix[j][k] - (rap * matrix[i][k])

    for (int i = 0; i < this->dim; ++i)
    {
        for (int j = i; j < this->dim; ++j)
        {
            if ((this->v)[j][i] != Complex(0, 0))
            {
                Complex *tmp = (this->v)[i];
                (this->v)[i] = (this->v)[j];
                (this->v)[j] = tmp;
                break;
            }
        }
        for (int j = i + 1; j < this->dim; ++j)
        {
            if ((this->v)[i][i] != Complex(0, 0))
            {
                Complex rap = (this->v)[j][i] / (this->v)[i][i];
                for (int k = 0; k < this->dim; ++k)
                {
                    (this->v)[j][k] = (this->v)[j][k] - rap * (this->v)[i][k];
                }
            }
        }
    }
    Complex res(1, 0);
    for (int i = 0; i < this->dim; ++i)
    {
        res = res * (this->v)[i][i];
    }

    return res;
}

bool Matrice_patratica::isDiagonal()
{
    for (int i = 0; i < this->dim; ++i)
        for (int j = 0; j < this->dim; ++j)
            if ((this->v)[i][j] != Complex(0, 0) && i != j)
                return false;
    return true;
}

std::istream &operator>>(std::istream &is, Matrice_patratica &m)
{
    std::cout << "Introduceti nr de linii/coloane din matricea patratica:\n";
    is >> m.dim;

    for (int i = 0; i < m.dim; ++i)
    {
        for (int j = 0; j < m.dim; j++)
        {
            std::cout << "m[" << i << "][" << j << "] =\n";
            is >> (m.v)[i][j];
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Matrice_patratica &m)
{
    for (int i = 0; i < m.dim; ++i)
    {
        for (int j = 0; j < m.dim; ++j)
        {
            os << (m.v)[i][j] << " ";
        }
        os << "\n";
    }

    // os << "Determinantul este: " << m.calcDeterminant() << "\n";
    return os;
}

void Matrice_patratica::operator=(const Matrice_patratica &m)
{
    for (int i = 0; i < m.dim; ++i)
    {
        for (int j = 0; j < m.dim; j++)
        {
            (this->v)[i][j] = (m.v)[i][j];
        }
    }
}
