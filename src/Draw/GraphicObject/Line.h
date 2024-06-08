//
// Created by Hà Tường Nguyên on 5/21/24.
//

#ifndef COMPUTERGRAPHIC_LINE_H
#define COMPUTERGRAPHIC_LINE_H

#include "Object.h"

namespace graphic {
    /**
     * @class Line
     * @brief Represents a line segment between two points.
     *
     * This class defines a line segment based on two end points and provides functionality to display
     * it on a screen.
     */
    class Line : public Object {
    private:
        int x0, y0, x1, y1;  ///< Start point (x0, y0) and end point (x1, y1) of the line.

    private:
        /**
         * @brief Displays the line on a given screen and returns the screen.
         * @param screen A reference to a Screen object where the line will be displayed.
         * @return A reference to the modified Screen object.
         */
        inline Screen& displayOn(Screen& screen) const override;

    public:
        /**
         * @brief Constructor for the Line class.
         * @param x0 The x-coordinate of the start point.
         * @param y0 The y-coordinate of the start point.
         * @param x1 The x-coordinate of the end point.
         * @param y1 The y-coordinate of the end point.
         */
        Line(int x0, int y0, int x1, int y1);

        friend Screen& operator<<(Screen& screen, const Line* line);

        friend Screen& operator<<(Screen& screen, const Line& line);

        friend Screen& operator<<(Screen* screen, const Line& line);

        /**
         * @brief Destructor for Line.
         */
        ~Line() = default;
    };

} // graphic

#include "../../PixelScreen/Screen.h"

#endif //COMPUTERGRAPHIC_LINE_H
