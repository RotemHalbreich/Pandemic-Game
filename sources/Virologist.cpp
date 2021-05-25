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

        if (c == _current_city || _cards.contains(c))
        {
            if (_board.has_discovered_cure(c))
            {
                _cards.erase(c);
                _board[c] = 0;
            }
            else
            {
                _cards.erase(c);
                _board[c]--;
            }
            return *this;
        }
        throw invalid_argument("There is no such card in your hand!");
    }
}