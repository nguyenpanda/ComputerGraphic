//
// Created by Hà Tường Nguyên on 5/31/24.
//

#include "test_Circle.h"

namespace testcase {

    void all_circle() {
        circle0();
        circle1();
        circle2();
    }

    void circle0(int w, int h) {
        std::cout << color::YELLOW << "testcase::circle 0" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        std::cout << "------------------" << std::endl;
        scr << graphic::Circle(25, 25, 15);
        scr.drawcircle(25, 17, 5);
        scr.drawcircle(17, 25, 5);
        scr.drawcircle(25, 33, 5);
        scr.drawcircle(33, 25, 5);
        scr.drawcircle(3, 3, 1);
        scr.drawcircle(8, 8, 0);
        std::cout << scr;
    }

    void circle1(int w, int h) {
        std::cout << color::YELLOW << "testcase::circle 1" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        std::cout << "------------------" << std::endl;
        for (int i = 0; i < 20; ++i) {
            scr.drawcircle(25, 25, i);
        }
        std::cout << scr;
    }

    void circle2(int w, int h) {
        std::cout << color::YELLOW << "testcase::circle 2" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        std::cout << "------------------" << std::endl;
        for (int i = 0; i < 15; ++i) {
            scr.drawcircle(2 * i, 20, i);
        }
        std::cout << scr;
    }

}
