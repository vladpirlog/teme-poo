#ifndef FIRMA_DISTRIBUTIE_H
#define FIRMA_DISTRIBUTIE_H

template <typename T>
class FirmaDistributie
{
private:
    int nrPersoane;
    int nrActori;
    T *persoane;

public:
    FirmaDistributie();
    FirmaDistributie(int, T*);
    ~FirmaDistributie();
};

#endif // FIRMA_DISTRIBUTIE_H
