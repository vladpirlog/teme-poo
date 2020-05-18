#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>
#include <iostream>

class Persoana
{
private:
    int cnp;
    std::string nume;
    std::string numeFilm;
    float procentIncasari;
public:
    Persoana();
    Persoana(int, std::string, std::string, float);

    Persoana &operator=(const Persoana &);

    friend std::istream &operator>>(std::istream &, Persoana &);
	friend std::ostream &operator<<(std::ostream &, const Persoana &);
};

#endif // PERSOANA_H
