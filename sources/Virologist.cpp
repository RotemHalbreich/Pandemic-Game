#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    //Can treat any city even if she's not in it, after tossing it's card
    Player &Virologist::treat(City c)
    {
        if (_board[c] == 0)
        {
            throw invalid_argument("There are already 0 disease cubes in this city!");
        }

        if (c != _current_city && !_cards.contains(c))
        {
            throw invalid_argument("There is no such card in your hand!");
        }
        else
        {
            if (!_board.has_discovered_cure(c))
            {
                _board[c]--;
                _cards.erase(c);
            }
            else
            {
                _board[c] = 0;
                _cards.erase(c);
            }
            return *this;
        }
    }
}