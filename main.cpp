#include "main.h"

namespace testcase {

    void change_at0(int w = 28, int h = 28) {
        std::cout << color::YELLOW << "testcase::change_at 0" << color::RESET << std::endl;

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

    void change_at1(int w = 28, int h = 28) {
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

    void change_at2(int w = 28, int h = 28) {
        std::cout << color::YELLOW << "testcase::change_at 2" << color::RESET << std::endl;

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
        std::cout << scr.to_text("change_at2.txt") << std::endl;
    }

    void draw0(int w = 28, int h = 28) {
        std::cout << color::YELLOW << "testcase::change_at 0" << color::RESET << std::endl;

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
        std::cout << "------------------" << std::endl;
        scr.drawline(width / 2, height / 2, width - 1, height - 1);
        std::cout << scr;
    }

    void draw1(int w = 100, int h = 100, int start = 0, size_t N = 100) {
        std::cout << color::YELLOW << "testcase::change_at 4" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        scr.setUp()->setMapChar(graphic::mapchar::std_dot);
        int width, height;
        scr.shape(width, height);

        if (N >= 50) {
            std::cout << color::RED << "U must change parameter N or x[], y[] array size" << color::RESET << std::endl;
            return;
        }

        // x [-16,16] |-> f(x) [-7.04,7.04]
        // ScreenCoordinate[f(x)] |-> (ScreenHeight-1) - f(x) + min[f(x),x<-[-16,16]]
        int x[50], y[50];
        std::iota(x, x + N, 0);
        std::transform(x, x + N, y, [height, start](int x) {
            return std::round((height - 1) - (std::pow(x + start, 3) - 300 * (x + start)) / 100 - 20);
        });

        std::cout << "------------------" << std::endl;
        scr.draw(x, y, 0, N);
        std::cout << scr;
        scr.to_text("draw1.parabola.txt");
    }

    void plot0(int w = 33, int h = 42, int x_start = -16, int x_end = 16) {
        std::cout << color::YELLOW << "testcase::plot 0" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.plot(x_start, x_end, [](int x) -> int {
            return (int) (std::pow(x, 3) / 100 - 3 * x);
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        scr.to_text("plot0.x^3.txt");
    }

    void plot1(int w = 50, int h = 36, int x_start = -24, int x_end = 24) {
        std::cout << color::YELLOW << "testcase::plot 1" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.plot(x_start, x_end, [](int x) -> int {
            return (int) (std::pow(x, 4) / 4000 - std::pow(x, 2) / 4);
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        scr.to_text("plot1.x^4.txt");
    }

}


int main() {
    std::cout << color::GREEN << "Start program" << color::RESET << std::endl;

//    testcase::change_at0();
//    testcase::change_at1();
//    testcase::change_at2(100, 100);

//    testcase::draw0();
//    testcase::draw1(33, 42, -16, 33);

//    testcase::plot0();
//    testcase::plot1(72, 90, -33, 33);


    std::cout << color::GREEN << "End program" << color::RESET << std::endl;
    return 0;
}
