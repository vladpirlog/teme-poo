#ifndef REGIZOR_H
#define REGIZOR_H

#include "Persoana.h"

class Regizor : private Persoana
{
private:
    float sumaFixa;
public:
    Regizor();
    Regizor(std::string, std::string, std::string, float, float);
};

#endif // REGIZOR_H
