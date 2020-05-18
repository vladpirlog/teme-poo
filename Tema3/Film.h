#ifndef FILM_H
#define FILM_H

#include <string>
#include <set>
#include <tuple>
#include "Persoana.h"

class Film
{
private:
    std::string nume;
    std::string tip;
    int durata;
    // std::set<std::tuple<Persoana, Film, Bonus>> arr;

public:
    Film();
    Film(std::string, std::string, int);

    Film &operator=(const Film &);

    friend std::istream &operator>>(std::istream &, Film &);
    friend std::ostream &operator<<(std::ostream &, const Film &);
};

#endif // FILM_H
