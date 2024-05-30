//
// Created by Hà Tường Nguyên on 5/28/24.
//

#ifndef COMPUTERGRAPHIC_SCREENSETTING_H
#define COMPUTERGRAPHIC_SCREENSETTING_H

#include "../Utility.h"

#include <iostream>
#include <cmath>

namespace graphic {

    class Screen;

    using MapCharFunc = void (*)(std::ostream&, int, const std::string&);

    namespace mapchar {
        const std::string std_whitespace = " .,:;+*?%S#@";
        const std::string std_dot = ".,:;+*?%S#@";
        const std::string invert_whitespace = "@#S%?*+;:,. ";
        const std::string invert_dot = "@#S%?*+;:,.";
    }

    class MapFunc {
    public:
        static void std_map(std::ostream& os, int pixel, const std::string& charSet);

        static void blue_if_max(std::ostream& os, int pixel, const std::string& charSet);

        static void two4_bit_map(std::ostream& os, int pixel, const std::string& charSet);
    };

}

namespace graphic {

    class ScreenSetting {
        friend Screen;

    private:
        std::string map_char;
        MapCharFunc map_func;

    public:
        explicit ScreenSetting(std::string _mapChar = mapchar::std_dot, MapCharFunc _func = MapFunc::blue_if_max);

        void setMapChar(std::string _mapChar);

        [[nodiscard]] std::string getMapChar() const;

        void setMapFunc(MapCharFunc _func);

        [[nodiscard]] MapCharFunc getMapFunc() const;
    };

}

#endif //COMPUTERGRAPHIC_SCREENSETTING_H
