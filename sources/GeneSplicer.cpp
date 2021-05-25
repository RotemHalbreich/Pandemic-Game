#include "GeneSplicer.hpp"

using namespace std;

const int FIVE_CARDS = 5;

namespace pandemic
{
    //Can discover a cure with any '5' cards (the color isn't relevant)
    Player &GeneSplicer::discover_cure(Color c)
    {
        if (_board.has_cure(c))
        {
            return *this;
        }

        if (!_board.has_stations(_current_city))
        {
            throw invalid_argument("This city doesn't have a research station!");
        }

        if (_cards.size() >= FIVE_CARDS)
        {
            int counter = 1;
            for (auto itr = _cards.begin(); itr != _cards.end(); counter++)
            {
                if (counter == FIVE_CARDS)
                {
                    break;
                }
                itr = _cards.erase(itr);
            }
        }
        else
        {
            throw invalid_argument("You don't have enough cards from the same colors!");
        }
        _board.cured_city(c);
        return *this;
    }
}