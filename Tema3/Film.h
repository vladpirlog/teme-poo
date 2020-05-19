#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>

class Film
{
private:
    std::string nume;
    std::string tip;
    int durata;

public:
    Film();
    Film(std::string, std::string, int);
    Film(const Film&);
    virtual ~Film();

    Film &operator=(const Film &);

    friend std::istream &operator>>(std::istream &, Film &);
    friend std::ostream &operator<<(std::ostream &, const Film &);
};

#endif // FILM_H
