#include "Actor.h"

float Actor::bonusPersonajPrincipal = 10;

Actor::Actor() : Persoana(), personajPrincipal(false) {}

Actor::Actor(int cnp,
             std::string nume,
             std::string numeFilm,
             float procentIncasari,
             bool personajPrincipal) : Persoana(cnp,
                                                nume,
                                                numeFilm,
                                                procentIncasari),
                                       personajPrincipal(personajPrincipal)
{
}

Actor::Actor(const Actor &a) : Persoana(static_cast<Persoana>(a)), personajPrincipal(a.personajPrincipal)
{
}

Actor &Actor::operator=(const Actor &a)
{
    this->cnp = a.cnp;
    this->nume = a.nume;
    this->numeFilm = a.numeFilm;
    this->procentIncasari = a.procentIncasari;
    this->personajPrincipal = a.personajPrincipal;
    return *this;
}

float Actor::getBonus() const
{
    return this->procentIncasari + (this->personajPrincipal ? Actor::bonusPersonajPrincipal : 0);
}

float Actor::getBonusPersonajPrincipal()
{
    return Actor::bonusPersonajPrincipal;
}

bool Actor::estePersonajPrincipal() const
{
    return this->personajPrincipal;
}

void Actor::afisare()
{
    std::cout << "Actor:\n";
    static_cast<Persoana>(*this).afisare();
    std::cout << "Este personaj principal: " << this->personajPrincipal << "\n";
}

std::istream &operator>>(std::istream &is, Actor &a)
{
    std::string n;
    is >> static_cast<Persoana &>(a);
    std::cout << "Este personaj principal(1 = adevarat, 0 = fals): ";
    is >> n;

    if (n == "1")
        a.personajPrincipal = true;
    else if (n == "0")
        a.personajPrincipal = false;
    else
        throw(InvalidType());

    return is;
}

std::ostream &operator<<(std::ostream &os, const Actor &a)
{
    os << "Actor:\n";
    os << (Persoana &)a;
    os << "Este personaj principal: " << a.personajPrincipal << "\n";
    return os;
}
