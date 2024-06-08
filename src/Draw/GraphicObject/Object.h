//
// Created by Hà Tường Nguyên on 5/22/24.
//

#ifndef COMPUTERGRAPHIC_OBJECT_H
#define COMPUTERGRAPHIC_OBJECT_H

#include <cmath>
#include "../../PixelScreen/Pixel.h"

namespace graphic {

    /**
     * @class Object
     * @brief Represents a basic graphical object in a 2D space.
     *
     * This class provides a common interface for all graphical objects, such as
     * circles, rectangles, and lines. It allows manipulation of the graphical
     * object's position and provides a method to draw the object.
     */
    class Object {
    protected:

        /**
         * @brief Displays the object on a given Screen object and returns the modified screen.
         *
         * This pure virtual function must be implemented by derived classes to define how the object
         * should be displayed on the provided screen.
         *
         * @param screen A reference to a Screen object where the object will be displayed.
         * @return A reference to the modified Screen object.
         */
        [[nodiscard]] virtual Screen& displayOn(Screen& screen) const = 0;

    public:
        /**
         * @brief Stream insertion operator to display the object on a screen.
         *
         * Overloads the stream insertion operator to provide a convenient way to display the object
         * on a screen using standard C++ streaming operations.
         *
         * @param screen A reference to a Screen object where the object will be displayed.
         * @return A reference to the modified Screen object.
         */
        virtual Screen& operator>>(Screen& screen) const;
        /**
         * @brief Stream insertion operator to display the object on a screen, using a pointer.
         *
         * Similar to the non-pointer version, but takes a pointer to a Screen object instead.
         *
         * @param screen A pointer to a Screen object where the object will be displayed.
         * @return A reference to the modified Screen object, if the pointer is not null.
         */
        virtual Screen& operator>>(Screen* screen) const;

    };

} // graphic

#endif //COMPUTERGRAPHIC_OBJECT_H
