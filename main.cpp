#include "main.h"

namespace tc {

    void test0(int w = 28, int h = 28) {
        std::cout << color::YELLOW << "testcase 0" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                scr.changeAt(255, 255, 255, x, y);
            }
        }

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;
    }

    void test1(int w = 28, int h = 28) {
        std::cout << color::YELLOW << "testcase 1" << color::RESET << std::endl;

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
        scr.to_text("gradient.txt");
    }

    void test2(int w = 28, int h = 28) {
        std::cout << color::YELLOW << "testcase 2" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        int x = width - 1;
        for (int y = 0; y < height; ++y) {
            scr.changeAt(255, 255, 255, x--, y);
            scr.changeAt(255, 255, 255, x, y);
            if (x < 2) break;
            scr.changeAt(255, 255, 255, --x, y);
        }

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;
        std::cout << scr.to_text("test2.txt") << std::endl;
    }

    void test3(int w = 28, int h = 28) {
        std::cout << color::YELLOW << "testcase 3" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;
        scr << graphic::Line(27, 17, 11, 27);
        scr.drawline(1, 1, 11, 5);
        std::cout << scr;
    }
}

int main() {
    std::cout << color::GREEN << "Start program" << color::RESET << std::endl;

//    tc::test0();
//    tc::test1();
//    tc::test2(100, 100);
    tc::test3();


    std::cout << color::GREEN << "End program" << color::RESET << std::endl;
    return 0;
}
