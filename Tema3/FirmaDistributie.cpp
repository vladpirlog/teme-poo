#include "FirmaDistributie.h"

template <typename T>
FirmaDistributie<T>::FirmaDistributie() : nrPersoane(0), nrActori(0)
{
    this->filme = new T[50];
}

template <typename T>
FirmaDistributie<T>::FirmaDistributie(int nrPersoane, T *persoane) : nrPersoane(nrPersoane)
{
    for (int i = 0; i < nrPersoane; i++)
    {
        this->persoane[i] = persoane[i];
    }
}

template <typename T>
FirmaDistributie<T>::~FirmaDistributie()
{
    delete[] this->persoane;
}
