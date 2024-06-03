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

    void custom_func() {

        // ADD YOUR CODE HERE
        graphic::Screen src(28,28);
        graphic::Screen temp_src = src;
        temp_src.drawrectangle(5,5,10,12);
        //graphic::Screen temp_src2(28,28);
        //temp_src.drawrectangle(5,5,10,10);
        //temp_src2 = src;
        //src.drawrectangle(5,5,10,10);
        src.drawrectangle(0,0,5,5);
        cout << src;


    }

}

#endif //COMPUTERGRAPHIC_CUSTOM_TEST_H
