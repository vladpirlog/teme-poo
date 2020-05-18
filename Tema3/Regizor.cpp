#include "Regizor.h"

Regizor::Regizor() : Persoana(), sumaFixa(0) {}

Regizor::Regizor(std::string cnp,
                 std::string nume,
                 std::string numeFilm,
                 float procentIncasari,
                 float sumaFixa) : Persoana(cnp,
                                            nume,
                                            numeFilm,
                                            procentIncasari),
                                   sumaFixa(sumaFixa) {}
