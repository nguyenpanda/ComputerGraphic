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

    namespace mapchar {
        const std::string std_whitespace = " .,:;+*?%S#@";
        const std::string std_dot = ".,:;+*?%S#@";
        const std::string invert_whitespace = "@#S%?*+;:,. ";
        const std::string invert_dot = "@#S%?*+;:,.";
        const std::string none_char = " ";
    }

    using mapfunc = void (*)(std::ostream&, int, const std::string&);

    class MapFunc { // Contains only static methods having type mapfunc
    public:
        static void std_map(std::ostream& os, int pixel, const std::string& charSet);

        static void blue_if_out(std::ostream& os, int pixel, const std::string& charSet);

        static void two4_bit(std::ostream& os, int pixel, const std::string& charSet);

        static void eight_bit(std::ostream& os, int pixel, const std::string& charSet);
    };

}

namespace graphic {

    class ScreenSetting {
        friend Screen;

    private:
        std::string map_char;
        mapfunc map_func;

    public:
        explicit ScreenSetting(std::string _mapChar = mapchar::std_dot, mapfunc _func = MapFunc::two4_bit);

        void setMapChar(std::string _mapChar);

        [[nodiscard]] std::string getMapChar() const;

        void setMapFunc(mapfunc _func);

        [[nodiscard]] mapfunc getMapFunc() const;
    };

}

#endif //COMPUTERGRAPHIC_SCREENSETTING_H
