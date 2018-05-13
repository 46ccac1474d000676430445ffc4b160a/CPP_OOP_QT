#include "predator.hpp"

Predator::Predator()
{
}

Predator::Predator(const char *name, const char *description, double weight) :
    Mammal(name, description, weight)
{
}
