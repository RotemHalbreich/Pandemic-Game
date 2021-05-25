#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{
    //Can treat a disease in the city he's in and in all it's neighbors cities on the map without tossing a card

    Player &FieldDoctor::treat(City c)
    {
        if (_board[c] == 0)
        {
            throw invalid_argument("There are already 0 disease cubes in this city!");
        }

        if (c == _current_city || Board::is_connected(_current_city, c) || Board::is_connected(c, _current_city))
        {
            if (!_board.has_discovered_cure(c))
            {
                _board[c]--;
            }
            else
            {
                _board[c] = 0;
            }
            return *this;
        }
        throw invalid_argument("There is no such card in your hand!");
    }
}