//
// Created by Hà Tường Nguyên on 5/24/24.
//

#ifndef COMPUTERGRAPHIC_CIRCLE_H
#define COMPUTERGRAPHIC_CIRCLE_H

#include "Object.h"

namespace graphic {
    /**
     * @class Circle
     * @brief Represents a circle.
     *
     * This class defines a circle with a specific radius and provides functionality to display
     * it on a screen.
     */
    class Circle : public Object {
    private:
        int x, y, r;     ///< Center coordinates (x, y) and radius (r) of the circle.

    private:
        /**
         * @brief Displays the circle on a given screen and returns the screen.
         * @param screen A reference to a Screen object where the circle will be displayed.
         * @return A reference to the modified Screen object.
         */
        inline Screen& displayOn(Screen& screen) const override;

    public:
        /**
         * @brief Constructor for the Circle class.
         * @param x The x-coordinate of the center of the circle.
         * @param y The y-coordinate of the center of the circle.
         * @param r The radius of the circle.
         */
        Circle(int x, int y, int r);

        friend Screen& operator<<(Screen& screen, const Circle* circle);

        friend Screen& operator<<(Screen& screen, const Circle& circle);

        friend Screen& operator<<(Screen* screen, const Circle& circle);
        /**
         * @brief Destructor for Circle.
         */
        ~Circle() = default;

    };

}

#include "../../PixelScreen/Screen.h"

#endif //COMPUTERGRAPHIC_CIRCLE_H
