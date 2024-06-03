//
// Created by Hà Tường Nguyên on 5/28/24.
//

#ifndef COMPUTERGRAPHIC_SCREENSETTING_H
#define COMPUTERGRAPHIC_SCREENSETTING_H

#include "../Utility.h"
#include "Pixel.h"

#include <iostream>
#include <cmath>
#include <string>
#include <cstdarg>

// Pre-define block
namespace graphic {

    class Screen;

    namespace mapchar {
        const std::string std_whitespace = " .,:;+*?%S#@";
        const std::string std_dot = ".,:;+*?%S#@";
        const std::string invert_whitespace = "@#S%?*+;:,. ";
        const std::string invert_dot = "@#S%?*+;:,.";
        const std::string none_char = " ";
    }

    // @formatter:off
    // This block of codes is used to abbreviate function type
    using indexfunc = int (*)(int, const std::string&);
    using colorfunc = std::string (*)(uint8_t r, uint8_t g, uint8_t b);
    using mapfunc   = void (*)(std::ostream&, const Pixel&, const std::string&, indexfunc, colorfunc);
    // @formatter:on

}

// MapFunc
namespace graphic {

    class MapFunc { // Contains only static methods having mapfunc type
    public: // Built-in define MapFunc for users
        // @formatter:off
        static void std_map(std::ostream& os, const Pixel& pixel, const std::string& charSet, indexfunc _ifunc, colorfunc _cfunc);
        static void blue_if_out(std::ostream& os, const Pixel& pixel, const std::string& charSet, indexfunc _ifunc, colorfunc _cfunc);
        static void two4_bit(std::ostream& os, const Pixel& pixel, const std::string& charSet, indexfunc _ifunc, colorfunc _cfunc);
        static void gray_scale(std::ostream& os, const Pixel& pixel, const std::string& charSet, indexfunc _ifunc, colorfunc _cfunc);
        static void no_char(std::ostream& os, const Pixel& pixel, const std::string& charSet,indexfunc _ifunc, colorfunc _cfunc);
        // @formatter:on
    };

}

// IndexFunc
namespace graphic {

    class IndexFunc { // Contains only static methods having indexfunc type
    public: // Built-in define IndexFunc for users
        // @formatter:off
        static int linear(int pixel, const std::string& charSet);
        // @formatter:on
    };

}

// ScreenSetting
namespace graphic {

    class ScreenSetting {
        friend Screen;

    private:
        mapfunc map_func;
        colorfunc color_func;
        indexfunc ind_func;
        std::string map_char;

    public:
        // @formatter:off
        explicit ScreenSetting(std::string _mapChar = mapchar::none_char,
                               mapfunc        _func = MapFunc::two4_bit,
                               colorfunc     _cfunc = color::two4Bit::background,
                               indexfunc     _ifunc = IndexFunc::linear
                               );
        // @formatter:on

        ScreenSetting& operator=(const ScreenSetting& other);

        void setMapChar(std::string _mapChar);

        [[nodiscard]] std::string getMapChar() const;

        void setMapFunc(mapfunc _func);

        [[nodiscard]] mapfunc getMapFunc() const;

        void setColorFunc(colorfunc _cfunc);

        [[nodiscard]] colorfunc getColorFunc() const;

        void setIndexFunc(indexfunc _ifunc);

        [[nodiscard]] indexfunc getIndexFunc() const;
    };

}

#endif //COMPUTERGRAPHIC_SCREENSETTING_H
