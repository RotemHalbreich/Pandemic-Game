#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int _n;

    public:
        Scientist(Board &b, City c, int num) : Player(b, c, "Scientist"), _n(num) {}
        Player &discover_cure(Color c);
    };
}