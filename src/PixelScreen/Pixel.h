//
// Created by Hà Tường Nguyên on 5/22/24.
//

#ifndef COMPUTERGRAPHIC_PIXEL_H
#define COMPUTERGRAPHIC_PIXEL_H

#include "../Utility/color.h"
#include <cstdint>
#include <ostream>

namespace graphic {

    class Screen;

    /**
     * @brief Represents a pixel with red, green, blue, and alpha components.
     * This class is the main components of the graphic::Screen class
     *
     * The Pixel class provides methods for setting and retrieving the color
     * components of a pixel. It supports various constructors for different
     * use cases, including setting all components to the same value (grey),
     * setting individual RGB values, and including an alpha channel.
     */
    class Pixel {

        friend Screen;

        /**
         * @brief Overloads the << operator to print Pixel information.
         *
         * This friend function allows a Pixel object's RGB values to be printed
         * in the format (r, g, b).
         *
         * @param _cout The output stream object.
         * @param pixel The Pixel object to be printed.
         * @return The output stream object with the Pixel's RGB values.
         */
        friend std::ostream& operator<<(std::ostream& _cout, const Pixel& pixel);

    private:
        uint8_t r, g, b, a;

    public:
        [[maybe_unused]] Pixel();

        /**
         * @brief Sets the RGB color of a Pixel.
         *
         * This constructor initializes a Pixel with the specified color value.
         * The same color value is assigned to the red, green, and blue components
         * of the Pixel, resulting in a shade of grey.
         *
         * @param color The integer value to set the red, green, and blue components
         *              of the Pixel. This value should be between 0 (black) and 255 (white).
         */
        [[maybe_unused]] explicit Pixel(int color);

        /**
         * @brief Sets the RGB color of a Pixel.
         *
         * This constructor initializes a Pixel with the specified red, green, and blue values.
         *
         * @param _r The red component value.
         * @param _g The green component value.
         * @param _b The blue component value.
         */
        [[maybe_unused]] explicit Pixel(int _r, int _g, int _b);

        /**
         * @brief Sets the RGBA color of a Pixel.
         *
         * This constructor initializes a Pixel with the specified red, green, blue, and alpha values.
         *
         * @param _r The red component value.
         * @param _g The green component value.
         * @param _b The blue component value.
         * @param _a The alpha component value.
         */
        [[maybe_unused]] explicit Pixel(int _r, int _g, int _b, int _a);

        ~Pixel() = default;

        Pixel& operator=(const Pixel& other);

        /**
         * @brief Sets the RGB color of the Pixel.
         *
         * @param _r The red component value.
         * @param _g The green component value.
         * @param _b The blue component value.
         */
        void set(int _r, int _g, int _b);

        /**
         * @brief Sets the RGBA color of the Pixel.
         *
         * @param _r The red component value.
         * @param _g The green component value.
         * @param _b The blue component value.
         * @param _a The alpha component value.
         */
        void set(int _r, int _g, int _b, int _a);

        /**
         * @brief Sets the Pixel to a shade of grey.
         *
         * @param gray_value The grey value to set the red, green, and blue components.
         */
        void set(int gray_value);

        /**
         * @brief Sets the red component of the Pixel.
         *
         * @param _r The red component value.
         */
        void set_r(int _r);

        /**
         * @brief Sets the green component of the Pixel.
         *
         * @param _g The green component value.
         */
        void set_g(int _g);

        /**
         * @brief Sets the blue component of the Pixel.
         *
         * @param _b The blue component value.
         */
        void set_b(int _b);

        /**
         * @brief Sets the alpha component of the Pixel.
         *
         * @param _a The alpha component value.
         */
        void set_alpha(int _a);

        /**
         * @brief Converts the Pixel to a shade of grey.
         */
        void to_gray();

        /**
         * @brief Gets the red component of the Pixel.
         *
         * @return The red component value.
         */
        [[nodiscard]] [[maybe_unused]] uint8_t R() const;

        /**
         * @brief Gets the green component of the Pixel.
         *
         * @return The green component value.
         */
        [[nodiscard]] [[maybe_unused]] uint8_t G() const;

        /**
         * @brief Gets the blue component of the Pixel.
         *
         * @return The blue component value.
         */
        [[nodiscard]] [[maybe_unused]] uint8_t B() const;

        /**
         * @brief Gets the alpha component of the Pixel.
         *
         * @return The alpha component value.
         */
        [[nodiscard]] [[maybe_unused]] uint8_t A() const;

        /**
         * @brief Gets the grey value of the Pixel.
         *
         * @return The grey value.
         */
        [[nodiscard]] [[maybe_unused]] int gray() const;

        /**
         * @brief Creates a red Pixel.
         *
         * @param _a The alpha component value (default is 255).
         * @return A red Pixel with the specified alpha value.
         */
        [[maybe_unused]] static Pixel red(int _a = 255);

        /**
         * @brief Creates a green Pixel.
         *
         * @param _a The alpha component value (default is 255).
         * @return A green Pixel with the specified alpha value.
         */
        [[maybe_unused]] static Pixel green(int _a = 255);

        /**
         * @brief Creates a yellow Pixel.
         *
         * @param _a The alpha component value (default is 255).
         * @return A yellow Pixel with the specified alpha value.
         */
        [[maybe_unused]] static Pixel yellow(int _a = 255);

        /**
         * @brief Creates a blue Pixel.
         *
         * @param _a The alpha component value (default is 255).
         * @return A blue Pixel with the specified alpha value.
         */
        [[maybe_unused]] static Pixel blue(int _a = 255);

        /**
         * @brief Creates a magenta Pixel.
         *
         * @param _a The alpha component value (default is 255).
         * @return A magenta Pixel with the specified alpha value.
         */
        [[maybe_unused]] static Pixel magenta(int _a = 255);

        /**
         * @brief Creates a cyan Pixel.
         *
         * @param _a The alpha component value (default is 255).
         * @return A cyan Pixel with the specified alpha value.
         */
        [[maybe_unused]] static Pixel cyan(int _a = 255);

        /**
         * @brief Creates a white Pixel.
         *
         * @param _a The alpha component value (default is 255).
         * @return A white Pixel with the specified alpha value.
         */
        [[maybe_unused]] static Pixel white(int _a = 255);

        /**
         * @brief A struct for comparing Pixels based on their grayscale values.
         */
        struct Compare {

            struct Less {
                /**
                 * @brief Compares two Pixels and returns true if the first is less than the second.
                 *
                 * @param lhs The first Pixel to compare.
                 * @param rhs The second Pixel to compare.
                 * @return True if the grayscale value of lhs is less than that of rhs, otherwise false.
                 */
                bool operator()(Pixel& lhs, Pixel& rhs) { return lhs.gray() < rhs.gray(); }
            };

            struct Greater {
                /**
                 * @brief Compares two Pixels and returns true if the first is greater than the second.
                 *
                 * @param lhs The first Pixel to compare.
                 * @param rhs The second Pixel to compare.
                 * @return True if the grayscale value of lhs is greater than that of rhs, otherwise false.
                 */
                bool operator()(Pixel& lhs, Pixel& rhs) { return lhs.gray() > rhs.gray(); }
            };
        };

    };

}

#endif //COMPUTERGRAPHIC_PIXEL_H
