#include "Medic.hpp"

using namespace std;

namespace pandemic
{
    //If he treats a city, all the disease cubes will be deleted from that city instead of '1'
    //if there's already a cure for the disease, he automatically cures any city he's in
    //(deletes all cubes) without using "treat" method
    Player &Medic::treat(City c)
    {
        if (!(_current_city == c))
        {
            throw invalid_argument("The Medic is not in this city!");
        }
        if (_board[c] == 0)
        {
            throw invalid_argument("There are already 0 disease cubes in this city!");
        }
        _board[c] = 0;
        return *this;
    }
}