#ifndef PREDATOR_HPP
#define PREDATOR_HPP

#include "mammal.hpp"

class Predator : public Mammal, GeoRegion
{
public:
    Predator();
    Predator(const char *name, const char *description, double weight);

    virtual const char *feedingWay() const
    { return "eats herbivores"; }
};

#endif // PREDATOR_HPP
