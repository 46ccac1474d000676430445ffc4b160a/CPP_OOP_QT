#ifndef PLANET_H
#define PLANET_H

#include <ostream>
#include <cstring>


class Planet
{

protected:
    char Name[256] = {0};
    double Radius;
    double Mass;
    char System[256] = {0};

public:
    Planet();
    Planet(const char *name, double radius, double mass, const char *system);
    virtual ~Planet();

    void setName(const char *name);
    void setRadius(double radius);
    void setMass(double mass);
    void setSystem(const char *system);

    const char *name();
    double radius();
    double mass();
    const char *system();

    friend std::ostream& operator << (std::ostream &o, const Planet &p);

};

#endif // PLANET_H
