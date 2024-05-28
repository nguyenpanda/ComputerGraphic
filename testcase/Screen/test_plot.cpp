//
// Created by Hà Tường Nguyên on 5/28/24.
//

#include "test_plot.h"

namespace graphic {

    void plot0(int w, int h, int x_start, int x_end) {
        std::cout << color::YELLOW << "testcase::plot 0" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.plot(x_start, x_end, [](int x) -> int {
            return (int) (std::pow(x, 3) / 100 - 3 * x);
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        scr.to_text("plot0.x^3.txt");
    }

    void plot1(int w, int h, int x_start, int x_end) {
        std::cout << color::YELLOW << "testcase::plot 1" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.plot(x_start, x_end, [](int x) -> int {
            return (int) (std::pow(x, 4) / 4000 - std::pow(x, 2) / 4);
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        scr.to_text("plot1.x^4.txt");
    }

    void plot2(int w, int h, int x_start, int x_end) {
        std::cout << color::YELLOW << "testcase::plot 2" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.discretePlot(x_start, x_end, [](int x) -> int {
            return (int) (50 * std::sin(0.2 * x));
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        scr.to_text("plot2.sin.txt");
    }

    void plot3(int w, int h, int x_start, int x_end) {
        std::cout << color::YELLOW << "testcase::plot 3" << color::RESET << std::endl;

        graphic::Screen scr(w, h);

        scr.plot(x_start, x_end, [](int x) -> int {
            return (int) (50 * std::sin(0.2 * x));
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        scr.to_text("plot3.sin.txt");
    }

}
