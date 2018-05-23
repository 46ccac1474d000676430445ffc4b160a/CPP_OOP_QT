#ifndef TIGER_HPP
#define TIGER_HPP

#include "Base/predator.hpp"

class Tiger : public Predator
{
public:
    Tiger();
    Tiger(const char *name, const char *description, double weight);

    virtual const char *feedingWay() const
    { return ""; }

    virtual const char *habitat() const
    { return ""; }

    virtual DangerLevel dangerLevel() const
    { return Agressive; }

    virtual const char *regionName() const
    { return ""; }

    virtual const char *regionDescription() const
    { return ""; }

};

#endif // TIGER_HPP
