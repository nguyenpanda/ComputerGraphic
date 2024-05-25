//
// Created by Hà Tường Nguyên on 5/21/24.
//

#ifndef COMPUTERGRAPHIC_LINE_H
#define COMPUTERGRAPHIC_LINE_H

#include "Object.h"

namespace graphic {

    class Line : public Object {
    private:
        int x0, y0, x1, y1;

    private:
        inline Screen& displayOn(Screen& screen) const override;

    public:
        Line(int x0, int y0, int x1, int y1);

        friend Screen& operator<<(Screen& screen, const Line*& line);

        friend Screen& operator<<(Screen& screen, const Line& line);

        friend Screen& operator<<(Screen* screen, const Line& line);

        ~Line() = default;
    };

} // graphic

#include "../Screen.h"

#endif //COMPUTERGRAPHIC_LINE_H
