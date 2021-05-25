#include "Researcher.hpp"

using namespace std;

const int FIVE_CARDS = 5;

namespace pandemic
{
    //Can discover a cure in any city, even if there isn't a research station in it
    Player &Researcher::discover_cure(Color c)
    {
        if (_board.has_cure(c))
        {
            return *this;
        }

        int num_of_cards = 0;
        for (const auto itr : _cards)
        {
            if (Board::city_color(itr) == c)
            {
                num_of_cards++;
            }
        }

        if (num_of_cards >= FIVE_CARDS)
        {
            num_of_cards = 1;
            for (auto itr = _cards.begin(); itr != _cards.end(); num_of_cards++)
            {
                if (num_of_cards == FIVE_CARDS)
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
        
        return *this;
    }
}