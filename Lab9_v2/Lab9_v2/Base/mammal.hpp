#ifndef MAMMAL_HPP
#define MAMMAL_HPP

#include <cstring>

class Mammal
{
    char m_name[1024];
    char m_description[1024];
    double m_weight;

public:
    enum DangerLevel
    {
        NotDangerous,
        Quiet,
        Bluff,
        Dangerous,
        Agressive,
        VeryAgressive,
        Furious
    };

    Mammal();
    Mammal(const char *name, const char *description, double weight);

    const char *name() const
    { return m_name; }

    void rename(const char *name)
    { strcpy(m_name, name); }

    const char *description() const
    { return m_description; }

    void setDescription(const char *description)
    { strcpy(m_description, description); }

    double weight() const
    { return m_weight; }

    void setWeight(double weight)
    { m_weight = weight; }

    virtual const char *feedingWay() const = 0;
    virtual const char *habitat() const = 0;

    virtual DangerLevel dangerLevel() const = 0;

};

class GeoRegion
{
public:
    virtual const char *regionName() = 0;
    virtual const char *regionDescription() = 0;

};

#endif // MAMMAL_HPP
