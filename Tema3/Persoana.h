#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>
#include <iostream>
#include "InvalidType.h"
#include "InvalidPercentage.h"

class Persoana
{
protected:
    int cnp;
    std::string nume;
    std::string numeFilm;
    float procentIncasari;

public:
    Persoana();
    Persoana(int, std::string, std::string, float);
    Persoana(const Persoana &);
    virtual ~Persoana();

    Persoana &operator=(const Persoana &);
    virtual void afisare();
    virtual float getBonus() const;

    friend std::istream &operator>>(std::istream &, Persoana &);
    friend std::ostream &operator<<(std::ostream &, const Persoana &);
};

#endif // PERSOANA_H
