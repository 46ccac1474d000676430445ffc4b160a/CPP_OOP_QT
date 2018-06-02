#ifndef HERBIVORE_HPP
#define HERBIVORE_HPP

#include "mammal.hpp"

class Herbivore : public Mammal, public GeoRegion
{
public:
    Herbivore();
    Herbivore(const char *name, const char *description, double weight);

    virtual const char *feedingWay() const
    { return "eats herb"; }
};

#endif // HERBIVORE_HPP
