//
// Created by Hà Tường Nguyên on 5/27/24.
//

#include "performance.h"

double executeTime(void (* func)()) {
    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    double result = (double) duration.count() / 1e6;
    std::cout << "Execute time: " << std::setprecision(6) << result << " s";
    return result;
}