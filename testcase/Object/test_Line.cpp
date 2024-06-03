//
// Created by Hà Tường Nguyên on 5/25/24.
//

#include "test_Line.h"

namespace testcase {

    void all_line() {
        line0();
        line1();
        line2();
        line3();
    }

    void line0(int w, int h) {
        std::cout << color::YELLOW << "testcase::line 0" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;
        scr << graphic::Line(27, 17, 11, 27);
        scr.drawline(1, 1, 11, 5);
        std::cout << scr;
        scr.reset();
        std::cout << scr;
    }

    void line1(int w, int h) {
        std::cout << color::YELLOW << "testcase::line 1" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;
        scr << graphic::Line(27, 17, 11, 27);
        scr.drawline(1, 1, 11, 5);
        std::cout << scr;
        scr.drawline(width / 2, height / 2, width - 1, height - 1);
        std::cout << scr;
        scr.reset();
    }

    void line2(int w, int h) {
        std::cout << color::YELLOW << "testcase::line 2" << color::RESET << std::endl;

        graphic::Screen scr(w--, h--);
        int width, height;
        scr.shape(width, height);

        std::cout << "------------------" << std::endl;
        for (int i = 0; i < 11; ++i) {
            double alpha = i * M_PI / 20;
            int x = static_cast<int>(std::round(w * std::cos(alpha)));
            int y = static_cast<int>(std::round(h * std::sin(alpha)));
            scr.drawline(0, 0, x, y);
        }
        std::cout << scr;
    }

    void line3(int w, int h) {
        std::cout << color::YELLOW << "testcase::line 3" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        std::cout << "------------------" << std::endl;
        for (int i = 0; i < h - 1; ++i) {
            scr.drawline(1, i, --w, i);
        }
        std::cout << scr;
    }

}