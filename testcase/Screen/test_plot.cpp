//
// Created by Hà Tường Nguyên on 5/28/24.
//

#include "test_plot.h"

namespace testcase {

    void all_plot() {
        plot0();
        plot1();
        plot2();
        plot3();
    }

    void plot0(int w, int h, int x_start, int x_end) {
        std::cout << color::YELLOW << "testcase::plot 0" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.plot(0, w - 1, [](int x) -> int {
            return x;
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;

        scr.reset();

        scr.plot(x_start, x_end, [](int x) -> int {
            return (int) (std::pow(x, 3) / 100 - 3 * x);
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
    }

    void plot1(int w, int h, int x_start, int x_end) {
        std::cout << color::YELLOW << "testcase::plot 1" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.plot(x_start, x_end, [](int x) -> int {
            return (int) (std::pow(x, 4) / 4000 - std::pow(x, 2) / 4);
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
    }

    void plot2(int w, int h, int x_start, int x_end) {
        std::cout << color::YELLOW << "testcase::plot 2" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.discretePlot(x_start, x_end, [](int x) -> int {
            return (int) (50 * std::sin(0.2 * x));
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
    }

    void plot3(int w, int h, int x_start, int x_end) {
        std::cout << color::YELLOW << "testcase::plot 3" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.setUp()->setMapChar(graphic::mapchar::std_dot);

        scr.plot(x_start, x_end, [](int x) -> int {
            return (int) (100 * std::sin(0.01 * (x - 3)));
        });

        std::cout << "------------------" << std::endl;
        std::cout << "View .txt file at "
                  << color::two4Bit::background(255, 55, 66)
                  << scr.to_text("plot3.sin.txt")
                  << color::RESET
                  << " for large image" << std::endl;
    }

}
