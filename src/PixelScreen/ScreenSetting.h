//
// Created by Hà Tường Nguyên on 5/28/24.
//

#ifndef COMPUTERGRAPHIC_SCREENSETTING_H
#define COMPUTERGRAPHIC_SCREENSETTING_H

#include <iostream>

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
        static void mapChar(std::ostream& os, int pixel, const std::string& charSet);

        static void mapCharColor(std::ostream& os, int pixel, const std::string& charSet);
    };

}

namespace graphic {

    class ScreenSetting {
        friend Screen;

    private:
        std::string map_char;
        MapCharFunc map_func;

    public:
        explicit ScreenSetting(std::string _mapChar = mapchar::std_dot, MapCharFunc _func = MapFunc::mapCharColor);

        void setMapChar(std::string _mapChar);

        [[nodiscard]] std::string getMapChar() const;

        void setMapFunc(MapCharFunc _func);

        [[nodiscard]] MapCharFunc getMapFunc() const;
    };

}

#endif //COMPUTERGRAPHIC_SCREENSETTING_H
