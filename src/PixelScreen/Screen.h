//
// Created by Hà Tường Nguyên on 5/21/24.
//

#ifndef COMPUTERGRAPHIC_SCREEN_H
#define COMPUTERGRAPHIC_SCREEN_H

#include "Pixel.h"
#include "ScreenSetting.h"

#include "../Draw/GraphicObject.h"
#include "../ImageProcessing/Image.h"
#include "../Utility/PriorityQueue.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <filesystem>

namespace graphic {

    /**
     * @brief Represents a virtual screen for drawing operations.
     *
     * The Screen class provides functionality to manipulate and draw on a virtual screen.
     * It allows setting individual pixels, drawing lines, circles, rectangles, and other
     * geometric shapes, as well as exporting the screen content to various formats.
     */
    class Screen {
        friend std::ostream& operator<<(std::ostream& os, const Screen& srn);

        friend std::ostream& operator<<(std::ostream& os, const Screen* srn);

        friend ScreenSetting;

    private:
        int width, height;                   /**< The width and height of the screen. */
        Pixel** pixels = nullptr;            /**< 2D array representing the pixels of the screen. */
        ScreenSetting* setting = nullptr;    /**< Settings for mapping pixel values to characters/colors. */

    public:
        /**
         * @brief Constructs a Screen with specified width and height.
         *
         * @param width The width of the screen, default is 1.
         * @param height The height of the screen, default is 1.
         */
        explicit Screen(int width = 1, int height = 1);

        /**
         * @brief Copy constructor for the Screen class.
         *
         * @param other The Screen object to copy from.
         */
        Screen(const Screen& other);

        /**
         * @brief Destructor for the Screen class.
         */
        ~Screen();

        /**
         * @brief Gets the width of the screen.
         *
         * @return The width of the screen.
         */
        [[nodiscard]] int getWidth() const;

        /**
         * @brief Gets the height of the screen.
         *
         * @return The height of the screen.
         */
        [[nodiscard]] int getHeight() const;

        /**
         * @brief Gets the dimensions of the screen.
         *
         * @param _width Reference to store the width of the screen.
         * @param _height Reference to store the height of the screen.
         */
        void shape(int& _width, int& _height) const;

        /**
         * @brief Gets the pointer to attribute `setting`.
         *
         * @return A pointer to the ScreenSettings object.
         */
        [[nodiscard]] ScreenSetting* setUp() const;

        /**
         * @brief Assignment operator for the Screen class.
         *
         * @param other The Screen object to assign from.
         * @return A reference to the assigned Screen object.
         */
        Screen& operator=(const Screen& other);

        /**
         * @brief Copies `other` Screen object to `this` object.
         *
         * @param other The Screen object to copy from.
         */
        void copy(const Screen& other);

        /**
         * @brief Copies the image content (attribute Pixel** pixel) of another Screen object.
         *
         * @param other The Screen object to copy the image from.
         */
        void copy_image(const Screen& other);

        /**
         * @brief Copies the image setting (attribute ScreenSetting* setting) of another Screen object.
         *
         * @param other The Screen object to copy the settings from.
         */
        void copy_setting(const Screen& other);

        /**
         * @brief Resizes the screen to the specified width and height. This method will delete all Pixel.
         *
         * @param w The new width of the screen.
         * @param h The new height of the screen.
         */
        void resize(int w, int h); // TODO REIMPLEMENT

        /**
         * @brief Gets the Pixel at the specified coordinates.
         *
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         * @return The Pixel at the specified coordinates.
         */
        [[nodiscard]] Pixel point(int x, int y) const;

        /**
         * @brief Gets a reference to the Pixel at the specified coordinates.
         *
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         * @return A reference to the Pixel at the specified coordinates.
         */
        Pixel& pixel(int x, int y);

        /**
         * @brief Resets the pixels in the specified column to their default state.
         *
         * @param x The x-coordinate of the column to reset.
         */
        void resetX(int x);

        /**
         * @brief Resets the pixels in the specified row to their default state.
         *
         * @param y The y-coordinate of the row to reset.
         */
        void resetY(int y);

        /**
         * @brief Resets all pixels on the screen to their default state.
         */
        [[maybe_unused]] void reset();

        /**
         * @brief Changes the pixel at the specified coordinates to the given Pixel object.
         *
         * @param pixel The Pixel object to set.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        void changeAt(const Pixel& pixel, int x, int y);

        /**
         * @brief Changes the pixel at the specified coordinates to the given color.
         *
         * @param color The color value to set (grey value).
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        void changeAt(int color, int x, int y);

        /**
         * @brief Changes the pixel at the specified coordinates to the given RGB values.
         *
         * @param r The red component value.
         * @param g The green component value.
         * @param b The blue component value.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        void changeAt(int r, int g, int b, int x, int y);

        /**
         * @brief Changes the pixel at the specified coordinates to the color specified by an array.
         *
         * @param arr An array containing the color values and coordinates in the order {r, g, b, x, y}.
         */
        void changeAt(const int (&arr)[5]);

        /**
         * @brief Fills the screen with colors from a vector. Noted that vec.size() >= width * height
         *
         * @param vec A vector containing the color values.
         */
        void fill(const std::vector<int>& vec);

        // File
        /**
         * @brief Converts the screen content to text and writes it to a file.
         *
         * @param filename The name of the file to write to.
         * @return The string representation of the screen content.
         */
        std::string to_text(const std::string& filename) const; // NOLINT(*-use-nodiscard)

        // Image
        /**
         * @brief Converts the screen to a grayscale image.
         */
        void gray_image();

        /**
         * @brief Exports the screen content as an image file. if file's extension is missing, .bmp as default.
         *
         * @param filename The name of the image file to write to.
         * @return The string representation of the export status.
         */
        std::string export_image(const std::string& filename) const; // NOLINT(*-use-nodiscard)

        // Draw
        /**
         * @brief Draws on the screen using the provided coordinates.
         *
         * @tparam N The size of the x-coordinate array.
         * @tparam M The size of the y-coordinate array.
         * @param x The array of x-coordinates.
         * @param y The array of y-coordinates.
         * @param startIdx The starting index in the arrays.
         * @param size The number of points to draw.
         */
        template<size_t N, size_t M>
        void draw(int (&x)[N], int (&y)[M], size_t startIdx, size_t size) {
            if (N < size) throw std::invalid_argument("Array's size of X < size");
            if (M < size) throw std::invalid_argument("Array's size of Y < size");

            for (size_t i = startIdx; i < size; ++i) {
                changeAt(255, 255, 255, x[i], y[i]);
            }
        }

        /**
         * @brief Plots a function on the screen.
         *
         * @param xStart The starting x-coordinate.
         * @param xEnd The ending x-coordinate.
         * @param f The function to plot.
         */
        void plot(int xStart, int xEnd, int (*f)(int));

        /**
         * @brief Plots a discrete function on the screen.
         *
         * @param xStart The starting x-coordinate.
         * @param xEnd The ending x-coordinate.
         * @param f The function to plot.
         */
        void discretePlot(int xStart, int xEnd, int (*f)(int));

        // Circle
        /**
         * @brief Draws a circle on the screen.
         *
         * @param x The x-coordinate of the circle's center.
         * @param y The y-coordinate of the circle's center.
         * @param r The radius of the circle.
         * @param hasCenter Whether to draw the center point of the circle.
         */
        void drawcircle(int x, int y, int r, bool hasCenter = false);

        // Line
        /**
         * @brief Draws a line on the screen.
         *
         * @param slope The slope of the line.
         * @param intercept The y-intercept of the line.
         */
        void drawline(float slope, float intercept);

        /**
         * @brief Draws a line on the screen within a specified x-range.
         *
         * @param slope The slope of the line.
         * @param intercept The y-intercept of the line.
         * @param xRange The x-range of the line.
         * @param x_max The maximum x-coordinate for the line.
         */
        void drawline(float slope, float intercept, int xRange, int x_max);

        /**
         * @brief Draws a line on the screen between two points.
         *
         * @param x0 The x-coordinate of the starting point.
         * @param y0 The y-coordinate of the starting point.
         * @param x1 The x-coordinate of the ending point.
         * @param y1 The y-coordinate of the ending point.
         */
        void drawline(int x0, int y0, int x1, int y1);

        // Rectangle
        /**
         * @brief Draws a rectangle on the screen.
         *
         * @param x The x-coordinate of the top-left corner of the rectangle.
         * @param y The y-coordinate of the top-left corner of the rectangle.
         * @param w The width of the rectangle.
         * @param h The height of the rectangle.
         */
        void drawrectangle(int x, int y, int w, int h);

    private:
        /**
         * @brief Checks if the specified coordinates are within the screen bounds.
         *
         * @param x The x-coordinate to check.
         * @param y The y-coordinate to check.
         * @throws std::out_of_range if the coordinates are out of the screen bounds.
         */
        void checkRange(int x, int y) const;

        /**
         * @brief Creates a 2D array of pixels with the specified width and height.
         *
         * @param w The width of the pixel array.
         * @param h The height of the pixel array.
         */
        void createPixels(int w, int h);

        /**
         * @brief Deletes the 2D array of pixels to free memory.
         */
        void deletePixels();

    };

} // graphic

#endif //COMPUTERGRAPHIC_SCREEN_H
