#include "Planet.h"


Planet::Planet()
{
    Radius = Mass = 0.;
}

Planet::Planet(const char *name, double radius, double mass, const char *system) :
    Radius(radius), Mass(mass)
{
    strcpy(Name, name);
    strcpy(System, system);
}

Planet::~Planet()
{
    //dtor
}

inline void Planet::setName(const char* name)
{
    strcpy(Name, name);
}

inline void Planet::setRadius(double radius)
{
    Radius = radius;
}

inline void Planet::setMass(double mass)
{
    Mass = mass;
}

inline void Planet::setSystem(const char* system)
{
    strcpy(System, system);
}

inline const char* Planet::name()
{
    return Name;
}

inline double Planet::radius()
{
    return Radius;
}

inline double Planet::mass()
{
    return Mass;
}

inline const char* Planet::system()
{
    return System;
}

std::ostream& operator << (std::ostream &o, const Planet &p)
{
    return o
    << p.Name << "  "
    << p.Radius << "  "
    << p.Mass << "  "
    << p.System;
}
