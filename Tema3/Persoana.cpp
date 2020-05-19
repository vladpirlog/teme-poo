#include "Persoana.h"

Persoana::Persoana() : cnp(0), nume(""), numeFilm(""), procentIncasari(0) {}

Persoana::Persoana(int cnp,
                   std::string nume,
                   std::string numeFilm,
                   float procentIncasari) : cnp(cnp),
                                            nume(nume),
                                            numeFilm(numeFilm),
                                            procentIncasari(procentIncasari) {}

Persoana::Persoana(const Persoana &p)
{
    this->cnp = p.cnp;
    this->nume = p.nume;
    this->numeFilm = p.numeFilm;
    this->procentIncasari = p.procentIncasari;
}

Persoana::~Persoana()
{
    // std::cout << "Persoana stearsa.\n";
}

float Persoana::getBonus()
{
    return this->procentIncasari;
}

Persoana &Persoana::operator=(const Persoana &p)
{
    this->cnp = p.cnp;
    this->nume = p.nume;
    this->numeFilm = p.numeFilm;
    this->procentIncasari = p.procentIncasari;
    return *this;
}

void Persoana::afisare()
{
    std::cout << "CNP: " << this->cnp << "\n";
    std::cout << "Nume: " << this->nume << "\n";
    std::cout << "Nume film: " << this->numeFilm << "\n";
    std::cout << "Procent incasari: " << this->procentIncasari << "\n";
}

std::istream &operator>>(std::istream &is, Persoana &p)
{
    try
    {
        std::string n;
        std::cout << "CNP: ";
        is >> n;
        p.cnp = std::stoi(n);
        std::cout << "Nume: ";
        is >> p.nume;
        std::cout << "Nume film: ";
        is >> p.numeFilm;
        std::cout << "Procent incasari: ";
        is >> n;
        p.procentIncasari = std::stof(n);
        if (p.procentIncasari > 100 || p.procentIncasari < 0)
            throw(InvalidPercentage());
        return is;
    }
    catch (const std::invalid_argument &e)
    {
        throw(InvalidType());
    }
}

std::ostream &operator<<(std::ostream &os, const Persoana &p)
{
    os << "CNP: " << p.cnp << "\n";
    os << "Nume: " << p.nume << "\n";
    os << "Nume film: " << p.numeFilm << "\n";
    os << "Procent incasari: " << p.procentIncasari << "\n";
    return os;
}
