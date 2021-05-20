#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{
    //Can treat a disease in the city he's in and in all it's neighbors cities on the map
    //without tossing a card
    Player &FieldDoctor::treat(City c)
    {
        return *this;
    }
}