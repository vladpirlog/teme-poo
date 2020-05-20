#ifndef REGIZOR_H
#define REGIZOR_H

#include "Persoana.h"

class Regizor : public Persoana
{
private:
    float sumaFixa;

public:
    Regizor();
    Regizor(int, std::string, std::string, float, float);
    Regizor(const Regizor &);

    Regizor &operator=(const Regizor &);
    void afisare();
    float getBonus() const;

    friend std::istream &operator>>(std::istream &, Regizor &);
    friend std::ostream &operator<<(std::ostream &, const Regizor &);
};

#endif // REGIZOR_H
