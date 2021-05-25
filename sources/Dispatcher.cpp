#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    //if he's in a research station, he can fly directly to any city without tossing a card
    Player &Dispatcher::fly_direct(City c)
    {
        if (_current_city == c)
        {
            throw invalid_argument("The Dispacher is already in this city!");
        }

        if (_board.has_stations(_current_city))
        {
            _current_city = c;
        }

        else
        {
            throw invalid_argument("The Dispacher can't use fly direct because there's no research station in the current city!");
        }
        return *this;
    }
}