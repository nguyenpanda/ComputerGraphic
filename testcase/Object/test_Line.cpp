//
// Created by Hà Tường Nguyên on 5/25/24.
//

#include "test_Line.h"

namespace testcase {

    void draw0(int w, int h) {
        std::cout << color::YELLOW << "testcase::draw 0" << color::RESET << std::endl;

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

    void draw1(int w, int h, int start, int N) {
        std::cout << color::YELLOW << "testcase::draw 4" << color::RESET << std::endl;

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

    void draw2(int w, int h) {
        std::cout << color::YELLOW << "testcase::draw 2" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        scr.setUp()->setMapChar(graphic::mapchar::std_dot);
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
        scr.to_text("draw2.circle.txt");
    }

}