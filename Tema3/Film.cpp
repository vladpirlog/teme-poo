#include "Film.h"

Film::Film() : nume(""), tip(""), durata(0) {}

Film::Film(std::string nume, std::string tip, int durata) : nume(nume), tip(tip), durata(durata) {}

Film::Film(const Film &f)
{
    this->nume = f.nume;
    this->tip = f.tip;
    this->durata = f.durata;
}

Film::~Film()
{
    // std::cout << "Persoana stearsa.\n";
}

Film &Film::operator=(const Film &f)
{
    this->nume = f.nume;
    this->tip = f.tip;
    this->durata = f.durata;
    return *this;
}

std::istream &operator>>(std::istream &is, Film &f)
{
    std::cout << "Nume: ";
    is >> f.nume;
    std::cout << "Tip: ";
    is >> f.tip;
    std::cout << "Durata: ";
    is >> f.durata;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Film &f)
{
    os << "Nume: " << f.nume << "\n";
    os << "Tip: " << f.tip << "\n";
    os << "Durata: " << f.durata << "\n";
    return os;
}
