//
// Created by Hà Tường Nguyên on 5/28/24.
//

#ifndef COMPUTERGRAPHIC_TEST_PLOT_H
#define COMPUTERGRAPHIC_TEST_PLOT_H

#include "../testcase.h"

namespace testcase {

    void all_plot();

    void plot0(int w = 33, int h = 42, int x_start = -16, int x_end = 16);

    void plot1(int w = 100, int h = 100, int x_start = -31, int x_end = 31);

    void plot2(int w = 200, int h = 101, int x_start = 0, int x_end = 199);

    void plot3(int w = 501, int h = 201, int x_start = 0, int x_end = 500);

}

#endif //COMPUTERGRAPHIC_TEST_PLOT_H
