//
// Created by Hà Tường Nguyên on 5/27/24.
//

#ifndef COMPUTERGRAPHIC_PERFORMANCE_H
#define COMPUTERGRAPHIC_PERFORMANCE_H

#include <iostream>
#include <iomanip>
#include <chrono>

double executeTime(void (* func)()) {
    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    double result = (double) duration.count() / 1e6;
    std::cout << "Execute time: " << std::setprecision(6) << result << " s";
    return result;
}

template<typename inputType>
double executeTime(void (* func)(inputType), inputType input) {
    auto start = std::chrono::high_resolution_clock::now();

    func(input);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    double result = (double) duration.count() / 1e6;
    std::cout << "Execute time: " << std::setprecision(6) << result << " s";
    return result;
}

#endif //COMPUTERGRAPHIC_PERFORMANCE_H
