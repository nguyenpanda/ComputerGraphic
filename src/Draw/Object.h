//
// Created by Hà Tường Nguyên on 5/22/24.
//

#ifndef COMPUTERGRAPHIC_OBJECT_H
#define COMPUTERGRAPHIC_OBJECT_H

#include <cmath>
#include "../Pixel.h"

namespace graphic {

    class Object {
    protected:
        [[nodiscard]] virtual Screen& displayOn(Screen& screen) const = 0;

    public:
        virtual Screen& operator>>(Screen& screen) const;

        virtual Screen& operator>>(Screen* screen) const;

        virtual Screen& operator>>(Screen*& screen) const;
    };

} // graphic

#endif //COMPUTERGRAPHIC_OBJECT_H
