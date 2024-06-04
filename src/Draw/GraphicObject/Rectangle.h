//
// Created by Hà Tường Nguyên on 5/28/24.
//

#ifndef COMPUTERGRAPHIC_RECTANGLE_H
#define COMPUTERGRAPHIC_RECTANGLE_H

#include "Object.h"

namespace graphic {

    class Rectangle : public Object {
    private:
        int x, y, w, h;

    private:
        inline Screen& displayOn(Screen& screen) const override;

    public:
        Rectangle(int x, int y, int w, int h);

        friend Screen& operator<<(Screen& screen, const Rectangle* rectangle);

        friend Screen& operator<<(Screen& screen, const Rectangle& rectangle);

        friend Screen& operator<<(Screen* screen, const Rectangle& rectangle);

        ~Rectangle() = default;

    };

}

#include "../../PixelScreen/Screen.h"

#endif //COMPUTERGRAPHIC_RECTANGLE_H
