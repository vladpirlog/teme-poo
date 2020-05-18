#include "Actor.h"

Actor::Actor() : Persoana(), personajPrincipal(false) {}

Actor::Actor(int cnp,
             std::string nume,
             std::string numeFilm,
             float procentIncasari,
             bool personajPrincipal) : Persoana(cnp,
                                                nume,
                                                numeFilm,
                                                procentIncasari),
                                       personajPrincipal(personajPrincipal) {}

float Actor::getBonusPersonajPrincipal()
{
    return bonusPersonajPrincipal;
}
