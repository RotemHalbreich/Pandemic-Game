#pragma once
#include <unordered_map>
#include <string>

namespace pandemic
{
    enum City
    {
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
    };

    std::string city_to_string(City c)
    {
        switch (c)
        {
        case Algiers:
            return "Algiers";
            break;
        case Atlanta:
            return "Atlanta";
            break;
        case Baghdad:
            return "Baghdad";
            break;
        case Bangkok:
            return "Bangkok";
            break;
        case Beijing:
            return "Beijing";
            break;
        case Bogota:
            return "Bogota";
            break;
        case BuenosAires:
            return "BuenosAires";
            break;
        case Cairo:
            return "Cairo";
            break;
        case Chennai:
            return "Chennai";
            break;
        case Chicago:
            return "Chicago";
            break;
        case Delhi:
            return "Delhi";
            break;
        case Essen:
            return "Essen";
            break;
        case HoChiMinhCity:
            return "HoChiMinhCity";
            break;
        case HongKong:
            return "HongKong";
            break;
        case Istanbul:
            return "Istanbul";
            break;
        case Jakarta:
            return "Jakarta";
            break;
        case Johannesburg:
            return "Johannesburg";
            break;
        case Karachi:
            return "Karachi";
            break;
        case Khartoum:
            return "Khartoum";
            break;
        case Kinshasa:
            return "Kinshasa";
            break;
        case Kolkata:
            return "Kolkata";
            break;
        case Lagos:
            return "Lagos";
            break;
        case Lima:
            return "Lima";
            break;
        case London:
            return "London";
            break;
        case LosAngeles:
            return "LosAngeles";
            break;
        case Madrid:
            return "Madrid";
            break;
        case Manila:
            return "Manila";
            break;
        case MexicoCity:
            return "MexicoCity";
            break;
        case Miami:
            return "Miami";
            break;
        case Milan:
            return "Milan";
            break;
        case Montreal:
            return "Montreal";
            break;
        case Moscow:
            return "Moscow";
            break;
        case Mumbai:
            return "Mumbai";
            break;
        case NewYork:
            return "NewYork";
            break;
        case Osaka:
            return "Osaka";
            break;
        case Paris:
            return "Paris";
            break;
        case Riyadh:
            return "Riyadh";
            break;
        case SanFrancisco:
            return "SanFrancisco";
            break;
        case Santiago:
            return "Santiago";
            break;
        case SaoPaulo:
            return "SaoPaulo";
            break;
        case Seoul:
            return "Seoul";
            break;
        case Shanghai:
            return "Shanghai";
            break;
        case StPetersburg:
            return "StPetersburg";
            break;
        case Sydney:
            return "Sydney";
            break;
        case Taipei:
            return "Taipei";
            break;
        case Tehran:
            return "Tehran";
            break;
        case Tokyo:
            return "Tokyo";
            break;
        case Washington:
            return "Washington";
            break;
        default:
            return "There isn't city";
            break;
        }
    }

    const std::unordered_map<City, Color> colors{
        {City::Algiers, Color::Black},
        {City::Atlanta, Color::Blue},
        {City::Baghdad, Color::Black},
        {City::Bangkok, Color::Red},
        {City::Beijing, Color::Red},
        {City::Bogota, Color::Yellow},
        {City::BuenosAires, Color::Yellow},
        {City::Cairo, Color::Black},
        {City::Chennai, Color::Black},
        {City::Chicago, Color::Blue},
        {City::Delhi, Color::Black},
        {City::Essen, Color::Blue},
        {City::HoChiMinhCity, Color::Red},
        {City::HongKong, Color::Red},
        {City::Istanbul, Color::Black},
        {City::Jakarta, Color::Red},
        {City::Johannesburg, Color::Yellow},
        {City::Karachi, Color::Black},
        {City::Khartoum, Color::Yellow},
        {City::Kinshasa, Color::Yellow},
        {City::Kolkata, Color::Black},
        {City::Lagos, Color::Yellow},
        {City::Lima, Color::Yellow},
        {City::London, Color::Blue},
        {City::LosAngeles, Color::Yellow},
        {City::Madrid, Color::Blue},
        {City::Manila, Color::Red},
        {City::MexicoCity, Color::Yellow},
        {City::Miami, Color::Yellow},
        {City::Milan, Color::Blue},
        {City::Montreal, Color::Blue},
        {City::Moscow, Color::Black},
        {City::Mumbai, Color::Black},
        {City::NewYork, Color::Blue},
        {City::Osaka, Color::Red},
        {City::Paris, Color::Blue},
        {City::Riyadh, Color::Black},
        {City::SanFrancisco, Color::Blue},
        {City::Santiago, Color::Yellow},
        {City::SaoPaulo, Color::Yellow},
        {City::Seoul, Color::Red},
        {City::Shanghai, Color::Red},
        {City::StPetersburg, Color::Blue},
        {City::Sydney, Color::Red},
        {City::Taipei, Color::Red},
        {City::Tehran, Color::Black},
        {City::Tokyo, Color::Red},
        {City::Washington, Color::Blue}};
}