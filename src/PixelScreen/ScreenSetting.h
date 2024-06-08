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

    /**
     * @brief Namespace containing predefined character sets for mapping pixels.
     *
     * The mapchar namespace contains predefined strings representing character sets
     * used for mapping pixels to characters. These strings define different mapping schemes
     * such as standard whitespace characters, dot characters, inverted characters, etc.
     */
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

    /**
     * @brief Contains static methods for mapping pixels to characters/colors.
     *
     * The MapFunc class provides static methods for mapping pixel values to characters/colors
     * based on predefined mapping schemes. These methods are used in conjunction with the ScreenSetting
     * class to define how pixels are rendered on the screen.
     */
    class MapFunc { // Contains only static methods having mapfunc type
    public: // Built-in define MapFunc for users
        // @formatter:off
        /**
         * @brief Standard map function to output pixel information. Support ASCII char.
         *
         * @param os The output stream to write the mapped pixel information.
         * @param pixel The Pixel object to map.
         * @param charSet The character set to use for mapping.
         * @param _ifunc The index function to determine the character index.
         * @param _cfunc The color function to determine the color based on pixel values.
         */
        static void std_map(std::ostream& os, const Pixel& pixel, const std::string& charSet, indexfunc _ifunc, colorfunc _cfunc);

        /**
         * @brief Map function that outputs blue with '@; if it over 255. Support ASCII char.
         *          * @brief Standard map function to output pixel information. Support ASCII char.
         *
         * @param os The output stream to write the mapped pixel information.
         * @param pixel The Pixel object to map.
         * @param charSet The character set to use for mapping.
         * @param _ifunc The index function to determine the character index.
         * @param _cfunc The color function to determine the color based on pixel values.
         */
        static void blue_if_out(std::ostream& os, const Pixel& pixel, const std::string& charSet, indexfunc _ifunc, colorfunc _cfunc);

        /**
         * @brief Map function for 24-bit color. Support ASCII char.
         *
         * @param os The output stream to write the mapped pixel information.
         * @param pixel The Pixel object to map.
         * @param charSet The character set to use for mapping.
         * @param _ifunc The index function to determine the character index.
         * @param _cfunc The color function to determine the color based on pixel values.
         */
        static void two4_bit(std::ostream& os, const Pixel& pixel, const std::string& charSet, indexfunc _ifunc, colorfunc _cfunc);

        /**
         * @brief Map function for grayscale output. Support ASCII char.
         *
         * @param os The output stream to write the mapped pixel information.
         * @param pixel The Pixel object to map.
         * @param charSet The character set to use for mapping.
         * @param _ifunc The index function to determine the character index.
         * @param _cfunc The color function to determine the color based on pixel values.
         */
        static void gray_scale(std::ostream& os, const Pixel& pixel, const std::string& charSet, indexfunc _ifunc, colorfunc _cfunc);

        /**
         * @brief Map function that outputs no character.
         *
         * @param os The output stream to write the mapped pixel information.
         * @param pixel The Pixel object to map.
         * @param charSet The character set to use for mapping.
         * @param _ifunc The index function to determine the character index.
         * @param _cfunc The color function to determine the color based on pixel values.
         */
        static void no_char(std::ostream& os, const Pixel& pixel, const std::string& charSet,indexfunc _ifunc, colorfunc _cfunc);
        // @formatter:on
    };

}

// IndexFunc
namespace graphic {

    /**
     * @brief Contains static methods for indexing pixels to characters.
     *
     * The IndexFunc class provides static methods for indexing pixel values to characters.
     * These methods are used in conjunction with map functions to determine the character
     * index based on the pixel value and the specified character set.
     */
    class IndexFunc { // Contains only static methods having indexfunc type
    public: // Built-in define IndexFunc for users
        // @formatter:off
        /**
         * @brief Linear index function for mapping pixel values to characters.
         *
         * @param pixel The pixel value to map.
         * @param charSet The character set to use for mapping.
         * @return The index of the character in the character set corresponding to the pixel value.
         */
        static int linear(int pixel, const std::string& charSet);
        // @formatter:on
    };

}

// ScreenSetting
namespace graphic {

    /**
     * @brief Represents settings for mapping pixel values to characters/colors.
     *
     * The ScreenSetting class encapsulates settings related to mapping pixel values
     * to characters and colors on the screen. It defines the mapping function, color function,
     * index function, and character set used for rendering pixels on the screen.
     */
    class ScreenSetting {
        friend Screen;

    private:
        mapfunc map_func;
        colorfunc color_func;
        indexfunc ind_func;
        std::string map_char;

    public:
        // @formatter:off
        /**
         * @brief Constructs a ScreenSetting with specified parameters.
         *
         * @param _mapChar The character set to be used for mapping.
         * @param _func The map function to be used.
         * @param _cfunc The color function to be used.
         * @param _ifunc The index function to be used.
         */
        explicit ScreenSetting(std::string _mapChar = mapchar::none_char,
                               mapfunc        _func = MapFunc::two4_bit,
                               colorfunc     _cfunc = color::two4Bit::background,
                               indexfunc     _ifunc = IndexFunc::linear
                               );
        // @formatter:on

        /**
         * @brief Assignment operator for the ScreenSetting class.
         *
         * @param other The ScreenSetting object to assign from.
         * @return A reference to the assigned ScreenSetting object.
         */
        ScreenSetting& operator=(const ScreenSetting& other);

        /**
         * @brief Sets the character set for mapping.
         *
         * @param _mapChar The string of character set to be used for mapping.
         */
        void setMapChar(std::string _mapChar);

        /**
         * @brief Gets the character set used for mapping.
         *
         * @return The string of character set used for mapping.
         */
        [[nodiscard]] std::string getMapChar() const;

        /**
         * @brief Sets the map function to be used.
         *
         * @param _func The map function to be used.
         */
        void setMapFunc(mapfunc _func);

        /**
         * @brief Gets the map function used.
         *
         * @return The map function used.
         */
        [[nodiscard]] mapfunc getMapFunc() const;

        /**
         * @brief Sets the color function to be used.
         *
         * @param _cfunc The color function to be used.
         */
        void setColorFunc(colorfunc _cfunc);

        /**
         * @brief Gets the color function used.
         *
         * @return The color function used.
         */
        [[nodiscard]] colorfunc getColorFunc() const;

        /**
         * @brief Sets the index function to be used.
         *
         * @param _ifunc The index function to be used.
         */
        void setIndexFunc(indexfunc _ifunc);

        /**
         * @brief Gets the index function used.
         *
         * @return The index function used.
         */
        [[nodiscard]] indexfunc getIndexFunc() const;
    };

}

#endif //COMPUTERGRAPHIC_SCREENSETTING_H
