#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <unordered_map>
#include <unordered_set>

namespace pandemic
{
    class Board
    {
    private:
        std::unordered_map<City, int> _disease_cubes;
        std::unordered_set<City> _research_stations;
        std::unordered_set<Color> _cures;

    public:
        int &operator[](City c);
        friend std::ostream &operator<<(std::ostream &os, const Board &b);
        bool is_clean();
        void remove_cures();
        void remove_stations();

        /**
         * MY FUNCTIONS:
         */
        static bool is_connected(City &src, City &dest);
        void remove_cubes(City c);
        bool has_stations(City c);
        void add_stations(City c);
        bool has_cure(Color c);
        static Color city_color(City c);
        void cured_city(Color c);
    };
}