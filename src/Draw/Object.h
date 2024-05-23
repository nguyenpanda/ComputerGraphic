//
// Created by Hà Tường Nguyên on 5/22/24.
//

#ifndef COMPUTERGRAPHIC_OBJECT_H
#define COMPUTERGRAPHIC_OBJECT_H

#include <cmath>
#pragma once // TODO DELETE
#include "../Pixel.h" // TODO DELETE
#include "../Screen.h" // TODO DELETE

namespace graphic {

    class Object {
    protected:
        [[nodiscard]] virtual Screen& displayOn(Screen& screen) const = 0;

    public:
        virtual Screen& operator>>(Screen& screen) const = 0;

        virtual Screen& operator>>(Screen* screen) const = 0;

        virtual Screen& operator>>(Screen*& screen) const = 0;
    };

} // graphic

#endif //COMPUTERGRAPHIC_OBJECT_H
