//
// Created by Hà Tường Nguyên on 5/28/24.
//

#include "test_changeAt.h"

namespace testcase {

    void all_change_at() {
        change_at0();
        change_at1();
        change_at2();
    }

    void change_at0(int w, int h) {
        std::cout << color::YELLOW << "testcase::change_at 0" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                scr.changeAt(255 - x, 255 - 2 * x - y, 255 - y, x, y);
            }
        }

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;
    }

    void change_at1(int w, int h) {
        std::cout << color::YELLOW << "testcase::change_at 1" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                uint8_t red = (255 * x) / (scr.getWidth() - 1);
                uint8_t green = (255 * y) / (scr.getHeight() - 1);
                uint8_t blue = (255 * (x + y)) / (scr.getWidth() + scr.getHeight() - 2);
                scr.changeAt(red, green, blue, x, y);
            }
        }

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;
        scr.to_text("change_at1.gradient.txt");
    }

    void change_at2(int w, int h) {
        std::cout << color::YELLOW << "testcase::change_at 2" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        int x = width - 1;
        for (int y = 0; y < height; ++y) {
            scr.changeAt(255, 0, 255, x--, y);
            scr.changeAt(255, 255, 0, x, y);
            scr.changeAt(0, 255, 255, --x, y);
        }

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;
        std::cout << scr.to_text("change_at2.txt") << std::endl;
    }

}