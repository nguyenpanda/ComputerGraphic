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
        Screen& displayOn(Screen& screen) const override {
            /*
            dx = abs(x1 - x0)
            dy = -abs(y1 - y0)

            sx = x0 < x1 ? 1 : -1
            sy = y0 < y1 ? 1 : -1

            error = dx + dy

            while true {
                plot(x0, y0)

                if x0 == x1 && y0 == y1
                    break

                e2 = 2 * error
                if e2 >= dy {
                    if x0 == x1 break
                    error = error + dy
                    x0 = x0 + sx
                }

                if e2 <= dx {
                    if y0 == y1
                        break

                    error = error + dx
                    y0 = y0 + sy
                }
            }
             */
            int dx = std::abs(x1 - x0), dy = std::abs(y1 - y0);
            int sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1;
            int error = dx + dy;

            int t_x0 = x0, t_y0 = y0, t_x1 = x1, t_y1 = y1;
            while (true) {
                screen.changeAt(255, 255, 255, t_x0, t_y0);

                if (t_x0 == t_x1 && t_y0 == t_y1) break;

                int e2 = 2 * error;

                if (e2 >= dy) {
                    if (t_x0 == t_x1) break;
                    error = error + dy;
                    t_x0 += sx;
                }

                if (e2 <= dx) {
                    if (t_y0 == t_y1) break;
                    error = error + dx;
                    t_y0 += sy;
                }
            }

            return screen;
        }

    public:
        Line(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}

        friend Screen& operator<<(Screen& screen, const Line*& line) {
            if (line == nullptr) return screen;
            return line->displayOn(screen);
        }

        friend Screen& operator<<(Screen& screen, const Line& line) {
            return line.displayOn(screen);
        }

        friend Screen& operator<<(Screen* screen, const Line& line) {
            return line.displayOn(*screen);
        }

        Screen& operator>>(Screen& screen) const override {
            return displayOn(screen);
        }

        Screen& operator>>(Screen* screen) const override {
            return displayOn(*screen);
        }

        Screen& operator>>(Screen*& screen) const override {
            return displayOn(*screen);
        }

        ~Line() = default;
    };

} // graphic

#endif //COMPUTERGRAPHIC_LINE_H
