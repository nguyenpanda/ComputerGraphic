//
// Created by Hà Tường Nguyên on 5/24/24.
//

#include "Circle.h"

namespace graphic {

    inline Screen& Circle::displayOn(Screen& screen) const {
        int t1 = r / 16;
        int t_x = r, t_y = 0;
        int w, h;
        screen.shape(w, h);
        w--;
        h--;

        while (t_x >= t_y) {
            // 4: vector(r) + vector(t_x, t_y)_i
            screen.changeAt(255, 255, 255, x + t_x, y + t_y);
            screen.changeAt(255, 255, 255, x + t_y, y + t_x);

            // 2: vector(r) + vector(-t_x, -t_y)_i
            screen.changeAt(255, 255, 255, x - t_x, y - t_y);
            screen.changeAt(255, 255, 255, x - t_y, y - t_x);

            // 1: vector(r) + vector(t_x, -t_y)_i
            screen.changeAt(255, 255, 255, x + t_x, y - t_y);
            screen.changeAt(255, 255, 255, x + t_y, y - t_x);

            // 3: vector(r) + vector(-t_x, t_y)_i
            screen.changeAt(255, 255, 255, x - t_x, y + t_y);
            screen.changeAt(255, 255, 255, x - t_y, y + t_x);

            t_y += 1;
            t1 += t_y;

            int t2 = t1 - t_x;
            if (t2 >= 0) {
                t1 = t2;
                --t_x;
            }
        }

        return screen;
    }

    Circle::Circle(int x, int y, int r) : x(x), y(y), r(r) {
        if (r < 0) throw std::invalid_argument("graphic::Circle::Circle: Radius must >= 0, got " + std::to_string(r));
    }

    Screen& operator<<(Screen& screen, const Circle* line) {
        if (line == nullptr) return screen;
        return line->displayOn(screen);
    }

    Screen& operator<<(Screen& screen, const Circle& line) {
        return line.displayOn(screen);
    }

    Screen& operator<<(Screen* screen, const Circle& line) {
        return line.displayOn(*screen);
    }

}
