#ifndef ACTOR_H
#define ACTOR_H

#include "Persoana.h"

class Actor : public Persoana
{
private:
    bool personajPrincipal;
    static float bonusPersonajPrincipal;

public:
    Actor();
    Actor(int, std::string, std::string, float, bool);
    Actor(const Actor &);

    Actor &operator=(const Actor &);
    float getBonus();
    bool estePersonajPrincipal();
    void afisare();

    friend std::istream &operator>>(std::istream &, Actor &);
    friend std::ostream &operator<<(std::ostream &, const Actor &);
};

#endif // ACTOR_H
