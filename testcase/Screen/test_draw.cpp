//
// Created by Hà Tường Nguyên on 5/31/24.
//

#include "test_draw.h"

namespace testcase {

    void all_draw() {
        draw0();
    }

    void draw0(int w, int h, int start, int N) {
        std::cout << color::YELLOW << "testcase::draw 0" << color::RESET << std::endl;

        graphic::Screen scr(w, h);
        int width, height;
        scr.shape(width, height);

        if (N >= 50) {
            std::cout << color::RED << "U must change parameter N or x[], y[] array size" << color::RESET << std::endl;
            return;
        }

        // x [-16,16] |-> f(x) [-7.04,7.04]
        // ScreenCoordinate[f(x)] |-> (ScreenHeight-1) - f(x) + min[f(x<-[-16,16])]
        int x[50], y[50];
        std::iota(x, x + N, 0);
        std::transform(x, x + N, y, [height, start](int x) {
            return std::round((height - 1) - (std::pow(x + start, 3) - 300 * (x + start)) / 100 - 20);
        });

        std::cout << "------------------" << std::endl;
        scr.draw(x, y, 0, N);
        std::cout << scr;
        scr.to_text("draw0.txt");
    }

}