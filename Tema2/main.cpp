#include "Matrice_patratica.h"
#include "Matrice_oarecare.h"

using namespace std;

int main()
{
    Matrice_patratica mp1;
    cin >> mp1;
    cout << "m[0][0] = " << mp1.at(0, 0) << endl;

    Matrice_patratica mp2 = Matrice_patratica(mp1);
    cout << "Matrice patratica 2:\n"
         << mp2 << endl;
    cout << "Matrice patratica 2 este diagonala: " << mp2.isDiagonal() << endl;

    Matrice_oarecare mo1;
    cin >> mo1;
    cout << "m[0][1] = " << mo1.at(0, 1) << endl;

    Matrice_oarecare mo2(mo1);
    cout << "Matrice oarecare 2:\n"
         << mo2 << endl;
    cout << "Matrice oarecare 2 este diagonala: " << mo2.isDiagonal() << endl;

    // se creeaza array-urile de pointeri pentru a le da ca argument constructorilor
    int dim = 3, lin = 2, col = 4;

    Complex **vOarecare = new Complex *[lin];
    for (int i = 0; i < lin; ++i)
        vOarecare[i] = new Complex[col];
    for (int i = 0; i < lin; ++i)
        for (int j = 0; j < col; ++j)
            vOarecare[i][j] = Complex(i, j);

    Complex **vPatratica = new Complex *[dim];
    for (int i = 0; i < dim; ++i)
        vPatratica[i] = new Complex[dim];
    for (int i = 0; i < dim; ++i)
        for (int j = 0; j < dim; ++j)
            vPatratica[i][j] = Complex(i, j);

    Matrice_oarecare mo3(lin, col, vOarecare);
    Matrice_patratica mp3(dim, vPatratica);
    cout << "Matrice oarecare 3:\n"
         << mo3 << endl;
    cout << "Matrice patratica 3:\n"
         << mp3 << endl;

    for (int i = 0; i < lin; ++i)
        delete[] vOarecare[i];
    delete[] vOarecare;
    for (int i = 0; i < dim; ++i)
        delete[] vPatratica[i];
    delete[] vPatratica;
    return 0;
}
