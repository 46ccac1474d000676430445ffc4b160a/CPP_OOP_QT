#include "herbivore.hpp"

Herbivore::Herbivore()
{
}

Herbivore::Herbivore(const char *name, const char *description, double weight) :
    Mammal(name, description, weight)
{
}
