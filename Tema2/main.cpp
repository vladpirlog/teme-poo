#include "Matrice_patratica.h"
#include "Matrice_oarecare.h"
#include "EmptyMatrix.h"
#include "NotAFloat.h"

using namespace std;

void citireMatriciPatratice(int n)
{
    Matrice_patratica *m = new Matrice_patratica[n];
    cout << "Citirea a " << n << " matrici patratice:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Citire matrice patratica " << i << ":\n";
        cin >> m[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << m[i];
    }
    delete[] m;
}

void citireMatriciOarecare(int n)
{
    Matrice_oarecare *m = new Matrice_oarecare[n];
    cout << "Citirea a " << n << " matrici oarecare:\n";

    for (int i = 0; i < n; ++i)
    {
        cout << "Citire matrice oarecare " << i << ":\n";
        cin >> m[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << m[i];
    }
    delete[] m;
}

int main()
{
    try
    {
        Matrice_patratica mp1;
        cin >> mp1;
        cout << "mp1[0][0] = " << mp1.at(0, 0) << endl;

        Matrice_patratica mp2 = Matrice_patratica(mp1);
        cout << "Matrice patratica 2:\n"
             << mp2 << endl;
        cout << "Matrice patratica 2 este diagonala: " << mp2.isDiagonal() << endl;

        Matrice_oarecare mo1;
        cin >> mo1;
        cout << "mo1[0][1] = " << mo1.at(0, 1) << endl;

        Matrice_oarecare mo2 = mo1;
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
                vOarecare[i][j] = Complex(i, -j);

        Complex **vPatratica = new Complex *[dim];
        for (int i = 0; i < dim; ++i)
            vPatratica[i] = new Complex[dim];
        for (int i = 0; i < dim; ++i)
            for (int j = 0; j < dim; ++j)
                vPatratica[i][j] = Complex(i, -j);

        Matrice_oarecare mo3(lin, col, vOarecare);
        Matrice_patratica mp3(dim, vPatratica);
        cout << "Matrice oarecare 3:\n"
             << mo3 << endl;
        cout << "Matrice patratica 3:\n"
             << mp3 << endl;

        int n;
        cout << "Introduceti nr de matrici oarecare ce tb citite si afisate:\n";
        cin >> n;
        citireMatriciOarecare(n);

        cout << "Introduceti nr de matrici patratice ce tb citite si afisate:\n";
        cin >> n;
        citireMatriciPatratice(n);

        for (int i = 0; i < lin; ++i)
            delete[] vOarecare[i];
        delete[] vOarecare;
        for (int i = 0; i < dim; ++i)
            delete[] vPatratica[i];
        delete[] vPatratica;
    }
    catch (const EmptyMatrix &e)
    {
        cout << e.what() << "\n";
    }
    catch (const NotAFloat &e)
    {
        cout << e.what() << "\n";
    }
    return 0;
}
