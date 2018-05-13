#include "mammal.hpp"

Mammal::Mammal() :
    m_weight(0.0)
{
}

Mammal::Mammal(const char *name, const char *description, double weight) :
    m_weight(weight)
{
    rename(name);
    setDescription(description);
}
