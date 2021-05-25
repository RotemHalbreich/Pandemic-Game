#include "Board.hpp"

#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace pandemic
{
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int &Board::operator[](City c)
    {
        return _disease_cubes[c];
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ostream &operator<<(ostream &os, const Board &b)
    {
        return os;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //returns true iff the board is clean from any cubes

    bool Board::is_clean()
    {
        for (auto &cube : _disease_cubes)
        {
            if (cube.second != 0)
            {
                return false;
            }
        }
        return true;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //removes all the cures that we already found

    void Board::remove_cures()
    {
        _cures.clear();
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //removes all the researchstations we already found -> no exception needed

    void Board::remove_stations()
    {
        _research_stations.clear();
    }

    /**
     * MY FUNCTIONS:
     */
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool Board::is_connected(City &src, City &dest)
    {
        return connected_cities[src].contains(dest);
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void Board::remove_cubes(City c)
    {
        if (_disease_cubes.contains(c))
        {
            _disease_cubes[c] = 0;
        }
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool Board::has_stations(City c)
    {
        return _research_stations.contains(c);
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void Board::add_stations(City c)
    {
        _research_stations.insert(c);
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool Board::has_cure(Color c)
    {
        return _cures.contains(c);
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Color Board::city_color(City c)
    {
        return colors_of_cities.at(c);
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool Board::has_discovered_cure(City c)
    {
        return _cures.contains(city_color(c));
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Color Board::city_color(City c)
    {
        return colors_of_cities.at(c);
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void Board::cured_city(Color c)
    {
        _cures.insert(c);
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //a map that holds all the connections of every city with it's neighbors as a set.

    static unordered_map<City, unordered_set<City>> connected_cities{
        {Algiers, {Madrid, Paris, Istanbul, Cairo}},
        {Atlanta, {Chicago, Miami, Washington}},
        {Baghdad, {Cairo, Istanbul, Karachi, Riyadh, Tehran}},
        {Bangkok, {Chennai, HoChiMinhCity, HongKong, Jakarta, Kolkata}},
        {Beijing, {Seoul, Shanghai}},
        {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
        {BuenosAires, {Bogota, SaoPaulo}},
        {Cairo, {Algiers, Baghdad, Istanbul, Khartoum, Riyadh}},
        {Chennai, {Bangkok, Delhi, Jakarta, Mumbai}},
        {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
        {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
        {Essen, {London, Paris, Milan, StPetersburg}},
        {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
        {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
        {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
        {Jakarta, {Bangkok, Chennai, HoChiMinhCity, Sydney}},
        {Johannesburg, {Khartoum, Kinshasa}},
        {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
        {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
        {Kinshasa, {Lagos, Khartoum, Johannesburg}},
        {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
        {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
        {Lima, {MexicoCity, Bogota, Santiago}},
        {London, {NewYork, Madrid, Essen, Paris}},
        {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
        {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
        {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
        {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
        {Miami, {Atlanta, Bogota, MexicoCity, Washington}},
        {Milan, {Essen, Istanbul, Paris}},
        {Montreal, {Chicago, NewYork, Washington}},
        {Moscow, {StPetersburg, Istanbul, Tehran}},
        {Mumbai, {Chennai, Delhi, Karachi}},
        {NewYork, {Montreal, London, Madrid, Washington}},
        {Osaka, {Taipei, Tokyo}},
        {Paris, {Algiers, Essen, Madrid, Milan, London}},
        {Riyadh, {Baghdad, Cairo, Karachi}},
        {SanFrancisco, {Chicago, LosAngeles, Manila, Tokyo}},
        {Santiago, {Lima}},
        {SaoPaulo, {BuenosAires, Bogota, Lagos, Madrid}},
        {Seoul, {Beijing, Shanghai, Tokyo}},
        {Shanghai, {Beijing, HongKong, Seoul, Taipei, Tokyo}},
        {StPetersburg, {Essen, Istanbul, Moscow}},
        {Sydney, {Jakarta, LosAngeles, Manila}},
        {Taipei, {Shanghai, HongKong, Osaka, Manila}},
        {Tehran, {Baghdad, Delhi, Karachi, Moscow}},
        {Tokyo, {Osaka, SanFrancisco, Seoul, Shanghai}},
        {Washington, {Atlanta, Miami, Montreal, NewYork}}};
}