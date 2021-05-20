#include "Player.hpp"
#include "City.hpp"

using namespace std;

const int FIVE_CARDS = 5;

namespace pandemic
{
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //drive from the current city to a neighbor city

    Player &Player::drive(City c)
    {
        if (!Board::is_connected(_current_city, c))
        {
            throw invalid_argument("These cities are not connected");
        }
        if (_current_city == c)
        {
            throw invalid_argument("You're already in this city!");
        }
        else
        {
            _current_city = c;
        }
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //fly from the current city to another city using it's card

    Player &Player::fly_direct(City c)
    {
        if (!_cards.contains(c))
        {
            throw invalid_argument("There is no such card in your hand!");
        }
        if (_current_city == c)
        {
            throw invalid_argument("You're already in this city!");
        }
        else
        {
            _cards.erase(c);
            _current_city = c;
        }
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //fly to any city using the current city's card

    Player &Player::fly_charter(City c)
    {
        if (!_cards.contains(_current_city))
        {
            throw invalid_argument("There is no such card in your hand!");
        }
        if (_current_city == c)
        {
            throw invalid_argument("You're already in this city!");
        }
        else
        {
            _cards.erase(_current_city);
            _current_city = c;
        }
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //if the current city has a RS, we can fly to any other city that has a RS

    Player &Player::fly_shuttle(City c)
    {
        if (_current_city == c)
        {
            throw invalid_argument("You're already in this city!");
        }
        if (_board.has_stations(c) && _board.has_stations(_current_city))
        {
            _current_city = c;
        }
        else
        {
            throw invalid_argument("These cities don't have a research station!");
        }
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //building a RS in a city we're on, using it's card
    //a city has one RS max, if we try to build another RS -> nothing happens

    Player &Player::build()
    {
        if (_board.has_stations(_current_city))
        {
            cout << "This city already has a research station!" << endl;
            return *this;
        }
        if (!_cards.contains(_current_city))
        {
            throw invalid_argument("There is no such card in your hand!");
        }
        else
        {
            _cards.erase(_current_city);
            _board.add_stations(_current_city);
        }
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //discover a cure to a disease of a specific color,
    //must be in a city with a RS and toss 5 cards from the same color
    //any disease has only one cure, if already got cure -> do nothing.

    Player &Player::discover_cure(Color c)
    {
        if (_board.has_cure(c))
        {
            return *this;
        }

        if (!_board.has_stations(_current_city))
        {
            throw invalid_argument("This city doesn't have a research station!");
        }

        int same_color_cards = 0;
        for (const auto itr : _cards)
        {
            if (Board::city_color(itr) == c)
            {
                same_color_cards++;
            }
        }

        if (same_color_cards >= FIVE_CARDS)
        {
            for (auto itr = _cards.begin(); itr != _cards.end(); same_color_cards++)
            {
                if (same_color_cards == FIVE_CARDS)
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
            }
        }
        else
        {
            throw invalid_argument("You don't have enough cards from the same colors!");
        }
        _board.cured_city(c);
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //decrease the disease cubes of the current city by 1, if there's
    //already a cure in the same color of the city -> decrease the city cubes to 0.
    //if there are already 0 cubes in the current city -> throw exception.

    Player &Player::treat(City c)
    {
        if (_board.has_cure(colors.at(c)))
        {
            _board[c] = 0;
        }
        if (_board[c] == 0)
        {
            throw invalid_argument("There are already 0 disease cubes in this city!");
        }
        _board[c]--;
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //an action which simulates the receiving of a card
    //there's only 1 card for each city on the board,
    //if you already have a specific card and you trying to take it again -> do nothing.

    Player &Player::take_card(City c)
    {
        _cards.insert(c);
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Player &Player::remove_cards()
    {
        _cards.clear();
        return *this;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //returns the role of the current player

    string Player::role()
    {
        return _role;
    }
}