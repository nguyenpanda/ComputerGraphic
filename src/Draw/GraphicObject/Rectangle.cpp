//
// Created by Hà Tường Nguyên on 5/28/24.
//

#include "Rectangle.h"

namespace graphic {

    inline Screen& Rectangle::displayOn(Screen& screen) const {
        int m = y + h - 1;
        int n = x + w - 1;
        for (int i = 0; i < w; ++i) {
            screen.changeAt(255, 255, 255, x + i, y);
            screen.changeAt(255, 255, 255, x + i, m);
        }

        for (int i = 1; i < h - 1; ++i) {
            screen.changeAt(255, 255, 255, x, y + i);
            screen.changeAt(255, 255, 255, n, y + i);
        }
        return screen;
    }

    Rectangle::Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

    Screen& operator<<(Screen& screen, const Rectangle* rectangle) {
        if (rectangle == nullptr) return screen;
        return rectangle->displayOn(screen);
    }

    Screen& operator<<(Screen& screen, const Rectangle& rectangle) {
        return rectangle.displayOn(screen);
    }

    Screen& operator<<(Screen* screen, const Rectangle& rectangle) {
        return rectangle.displayOn(*screen);
    }

} // graphic
