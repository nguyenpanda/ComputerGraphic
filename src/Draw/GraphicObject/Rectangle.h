//
// Created by Hà Tường Nguyên on 5/28/24.
//

#ifndef COMPUTERGRAPHIC_RECTANGLE_H
#define COMPUTERGRAPHIC_RECTANGLE_H

#include "Object.h"

namespace graphic {
    /**
     * @class Rectangle
     * @brief Represents a rectangle shape.
     *
     * This class defines a rectangle with specific dimensions and provides functionality to display
     * it on a screen.
     */
    class Rectangle : public Object {
    private:
        int x, y, w, h;     ///< Coordinates (x, y) and dimensions (width w, height h) of the rectangle.

    private:
        /**
         * @brief Displays the rectangle on a given screen and returns the screen.
         * @param screen A reference to a Screen object where the rectangle will be displayed.
         * @return A reference to the modified Screen object.
         */
        inline Screen& displayOn(Screen& screen) const override;

    public:
        /**
         * @brief Constructor for the Rectangle class.
         * @param x The x-coordinate of the rectangle.
         * @param y The y-coordinate of the rectangle.
         * @param w The width of the rectangle.
         * @param h The height of the rectangle.
         */
        Rectangle(int x, int y, int w, int h);

        friend Screen& operator<<(Screen& screen, const Rectangle* rectangle);

        friend Screen& operator<<(Screen& screen, const Rectangle& rectangle);

        friend Screen& operator<<(Screen* screen, const Rectangle& rectangle);

        /**
         * @brief Destructor for Rectangle.
         */
        ~Rectangle() = default;

    };

}

#include "../../PixelScreen/Screen.h"

#endif //COMPUTERGRAPHIC_RECTANGLE_H
