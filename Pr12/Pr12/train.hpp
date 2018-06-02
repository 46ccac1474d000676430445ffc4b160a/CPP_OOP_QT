#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <string>
#include <ostream>

#include "../../Pr4/Pr4/TimeClass.h"

using namespace std;

class Train
{
    unsigned m_number;

    string m_direction;

    TimeClass m_arrival;
    TimeClass m_departure;

public:
    Train();

    unsigned number() const;
    void setNumber(unsigned number);

    string direction() const;
    void setDirection(const string &direction);

    TimeClass arrival() const;
    void setArrival(const TimeClass &arrival);
    void setArrival(unsigned hour, unsigned min);

    TimeClass departure() const;
    void setDeparture(const TimeClass &departure);
    void setDeparture(unsigned hour, unsigned min);

    bool isOnStation(const TimeClass &time);
    bool isOnStation(unsigned hour, unsigned min);

    friend std::ostream &operator<<(ostream &o, const Train &train);
};

#endif // TRAIN_HPP
