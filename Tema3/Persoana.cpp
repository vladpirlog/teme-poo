#include "Persoana.h"

Persoana::Persoana() : cnp(0), nume(""), numeFilm(""), procentIncasari(0) {}

Persoana::Persoana(int cnp,
                   std::string nume,
                   std::string numeFilm,
                   float procentIncasari) : cnp(cnp),
                                            nume(nume),
                                            numeFilm(numeFilm),
                                            procentIncasari(procentIncasari) {}

Persoana &Persoana::operator=(const Persoana &p)
{
    this->cnp = p.cnp;
    this->nume = p.nume;
    this->numeFilm = p.numeFilm;
    this->procentIncasari = p.procentIncasari;
}

std::istream &operator>>(std::istream &is, Persoana &p)
{
    std::cout << "CNP: ";
    is >> p.cnp;
    std::cout << "Nume: ";
    is >> p.nume;
    std::cout << "Nume film: ";
    is >> p.numeFilm;
    std::cout << "Procent incasari: ";
    is >> p.procentIncasari;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Persoana &p)
{
    os << "CNP: " << p.cnp << "\n";
    os << "Nume: " << p.nume << "\n";
    os << "Nume film: " << p.numeFilm << "\n";
    os << "Procent incasari: " << p.procentIncasari << "\n";
    return os;
}
