//
// Created by Hà Tường Nguyên on 5/30/24.
//

#include "test_Rectangle.h"

namespace testcase {

    void all_rectangle() {
        rectangle0();
        rectangle1();
        rectangle2();
    }

    void rectangle0(int w, int h) {
        std::cout << color::YELLOW << "testcase::rectangle 0" << color::RESET << std::endl;

        graphic::Screen src(w, h);

        src << graphic::Rectangle(0, 0, 6, 6);
        src << graphic::Rectangle(1, 1, 5, 5);
        src << graphic::Rectangle(2, 2, 3, 3);
        src << graphic::Rectangle(0, 0, w, h);
        std::cout << "------------------" << std::endl;
        std::cout << src;
    }

    void rectangle1(int w, int h) {
        std::cout << color::YELLOW << "testcase::rectangle 1" << color::RESET << std::endl;
        graphic::Screen src(w, h);

        src.drawrectangle(3, 5, 3, 3);
        src.drawrectangle(8, 1, 7, 5);
        src.drawrectangle(8, 6, 8, 3);
        std::cout << "------------------" << std::endl;
        std::cout << src;
    }

    void rectangle2(int x, int y, int w, int h) {
        std::cout << color::YELLOW << "testcase::rectangle 2" << color::RESET << std::endl;
        graphic::Screen src(w, h);

        for (int i = 0; i < 6; ++i) {
            src.drawrectangle(x + i, y + i, 6 - i, 6 - i);
        }
        std::cout << "------------------" << std::endl;
        std::cout << src;
    }

}
