//
// Created by Hà Tường Nguyên on 5/25/24.
//

#ifndef COMPUTERGRAPHIC_TESTCASE_H
#define COMPUTERGRAPHIC_TESTCASE_H

#include "../src/GraphicScreen.h"

namespace testcase {

    void change_at0(int w = 28, int h = 28);

    void change_at1(int w = 28, int h = 28);

    void change_at2(int w = 28, int h = 28);

    void draw0(int w = 28, int h = 28);

    void draw1(int w = 100, int h = 100, int start = 0, size_t N = 100);

    void draw2(int w = 50, int h = 50);

    void plot0(int w = 33, int h = 42, int x_start = -16, int x_end = 16);

    void plot1(int w = 50, int h = 36, int x_start = -24, int x_end = 24);

}

#endif //COMPUTERGRAPHIC_TESTCASE_H
