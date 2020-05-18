#ifndef ACTOR_H
#define ACTOR_H

#include "Persoana.h"

class Actor : private Persoana
{
private:
    bool personajPrincipal;
    static const float bonusPersonajPrincipal = 10;
public:
    Actor();
    Actor(int, std::string, std::string, float, bool);

    static float getBonusPersonajPrincipal();
};

#endif // ACTOR_H
