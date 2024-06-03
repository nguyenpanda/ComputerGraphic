//
// Created by Hà Tường Nguyên on 5/31/24.
//

#ifndef COMPUTERGRAPHIC_CUSTOM_TEST_H
#define COMPUTERGRAPHIC_CUSTOM_TEST_H

#include "src/GraphicScreen.h"
#include "src/Utility.h"

#include <chrono>
#include <thread>
#include <unistd.h>
#include <cstring>
#include <algorithm>
#include <functional>
#include <random>
#include <typeinfo>

using std::cout;
using std::endl;

namespace cmdline {

    // ADD YOUR HELPER FUNCTION HERE
    double distance(int x0, int y0, int x1, int y1) {
        return std::hypot(x0 - x1, y0 - y1);
    }

    void custom_func() {

        // ADD YOUR CODE HERE
        int w = 171, h = 171;
        int cen_w = w / 2, cen_h = h / 2;

        graphic::Screen scr(w, h);
        for (int j = 0; j < h; ++j) {
            for (int i = 0; i < w; ++i) {
                int val = static_cast<int>(2 * distance(cen_w, cen_h, i, j));
                scr.changeAt(val, val, val, i, j);
            }
        }

        cout << scr;

    }

}

#endif //COMPUTERGRAPHIC_CUSTOM_TEST_H
