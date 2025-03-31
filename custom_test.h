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
        graphic::Screen screen;
        graphic::Bitmap("LTH-2") >> screen;
        std::cout << screen;

        int w, h;
        screen.shape(w, h);

        graphic::Bitmap("Emotional Damage_green=100") << screen;

    }

}

#endif //COMPUTERGRAPHIC_CUSTOM_TEST_H
