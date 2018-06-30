#include "train.hpp"

Train::Train() :
    m_number(0),
    m_arrival(0, 0, 0),
    m_departure(0, 0, 0)
{
}

unsigned Train::number() const
{ return m_number; }

void Train::setNumber(unsigned number)
{ m_number = number; }

string Train::direction() const
{ return m_direction; }

void Train::setDirection(const string &direction)
{ m_direction = direction; }

TimeClass Train::arrival() const
{ return m_arrival; }

void Train::setArrival(const TimeClass &arrival)
{ m_arrival = arrival; }

void Train::setArrival(unsigned hour, unsigned min)
{
    m_arrival.set_hour(hour > 23 ? 23 : hour);
    m_arrival.set_min(min > 59 ? 59 : min);
}

TimeClass Train::departure() const
{ return m_departure; }

void Train::setDeparture(const TimeClass &departure)
{  m_departure = departure; }

void Train::setDeparture(unsigned hour, unsigned min)
{
    m_departure.set_hour(hour > 23 ? 23 : hour);
    m_departure.set_min(min > 59 ? 59 : min);
}

bool Train::isOnStation(const TimeClass &time)
{ return m_arrival.less(time) && m_departure.more(time); }

bool Train::isOnStation(unsigned hour, unsigned min)
{
    TimeClass time(hour > 23 ? 23 : hour, min > 59 ? 59 : min, 0);
    return m_arrival.less(time) && m_departure.more(time);
}

ostream &operator<<(ostream &o, const Train &train)
{
    return o << "["
             << train.m_number << ", "
             << train.m_direction << ", "
             << train.m_arrival.get_hour() << ":" << train.m_arrival.get_min() << ", "
             << train.m_departure.get_hour() << ":" << train.m_departure.get_min() << "]";
}
