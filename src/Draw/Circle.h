//
// Created by Hà Tường Nguyên on 5/24/24.
//

#ifndef COMPUTERGRAPHIC_CIRCLE_H
#define COMPUTERGRAPHIC_CIRCLE_H

#include "Object.h"

namespace graphic {

    class Circle : public Object {
    private:
        int x, y, r;

    private:
        inline Screen& displayOn(Screen& screen) const override;

    public:
        Circle(int x, int y, int r);

        friend Screen& operator<<(Screen& screen, const Circle*& line);

        friend Screen& operator<<(Screen& screen, const Circle& line);

        friend Screen& operator<<(Screen* screen, const Circle& line);

        ~Circle() = default;
    };

}

#include "../Screen.h"

#endif //COMPUTERGRAPHIC_CIRCLE_H
