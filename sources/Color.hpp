#pragma once

namespace pandemic
{
    enum Color
    {
        Yellow,
        Red,
        Blue,
        Black
    };

    std::string color_to_string(Color color)
    {
        switch (color)
        {
        case Yellow:
            return "Yellow";
            break;

        case Red:
            return "Red";
            break;
            
        case Blue:
            return "Blue";
            break;

        case Black:
            return "Black";
            break;
        }
    }
}