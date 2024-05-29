//
// Created by Hà Tường Nguyên on 5/22/24.
//

#ifndef COMPUTERGRAPHIC_MAIN_H
#define COMPUTERGRAPHIC_MAIN_H

#include "src/GraphicScreen.h"
#include "src/Utility.h"
#include "testcase/testcase.h"
#include "test_application/test_application.h"

#include <chrono>
#include <thread>
#include <unistd.h>
#include <cstring>
#include <algorithm>
#include <functional>
#include <random>
#include <typeinfo>

void loadBar(int _ms = 2000, char _char = 'X', int step = 5) {
    int maxRange = 100 / step;
    _ms = _ms / maxRange;
    std::stringstream out;
    for (int i = 0; i < maxRange; i++) {
        out << _char;
        std::cout << std::flush << "\r" << step * i << "% [" << out.str() << ']';
        std::this_thread::sleep_for(std::chrono::milliseconds(_ms));
        if (i == 19) std::cout << std::flush << "\r" << 100 << "% " << "[ ...DONE... ]" << std::endl;
    }
}

#endif //COMPUTERGRAPHIC_MAIN_H
