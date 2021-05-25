#include "Scientist.hpp"

using namespace std;

namespace pandemic
{
    //Can discover a cure using only 'n' cards instead of '5'
    Player &Scientist::discover_cure(Color c)
    {
        if (_board.has_cure(c))
        {
            return *this;
        }

        if (_board.has_stations(_current_city))
        {
            int num_of_cards = 0;
            for (const auto itr : _cards)
            {
                if (Board::city_color(itr) == c)
                {
                    num_of_cards++;
                }
            }

            if (num_of_cards >= _n)
            {
                num_of_cards = 1;
                for (auto itr = _cards.begin(); itr != _cards.end(); num_of_cards++)
                {
                    if (num_of_cards == _n)
                    {
                        break;
                    }
                    if (Board::city_color(*itr) == c)
                    {
                        itr = _cards.erase(itr);
                    }
                    else
                    {
                        itr++;
                    }
                    _board.cured_city(c);
                }
            }
            else
            {
                throw invalid_argument("You don't have enough cards!");
            }
        }
        else
        {
            throw invalid_argument("This city doesn't have a research station!");
        }
        return *this;
    }
}