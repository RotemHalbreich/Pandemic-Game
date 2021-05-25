#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic
{
    //Can build in any city he's in without tossing a card
    
    Player &OperationsExpert::build()
    {
        _board.add_stations(_current_city);
        return *this;
    }
}