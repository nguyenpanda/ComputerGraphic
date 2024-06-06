//
// Created by Hà Tường Nguyên on 5/29/24.
//

#ifndef COMPUTERGRAPHIC_DATASET_H
#define COMPUTERGRAPHIC_DATASET_H

#include "../../src/GraphicScreen.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <cmath>

namespace AI {

    class Dataset {
    private:
        std::vector<std::vector<int>*>* feature = nullptr;
        std::vector<int>* target = nullptr;
        std::vector<int>* errorIdx;
        std::string path;

    public:
        explicit Dataset(std::string csv_path);

        ~Dataset();

        std::vector<int>& operator[](int idx) const;

        [[nodiscard]] std::vector<int>& get_error() const;

        void shape(int& num_of_data, int& num_of_feature) const;

        [[nodiscard]] int num_error() const;

        void print() const;

    };

    void test_mnist_animation(std::string csv);

    void test_mnist_bitmap(std::string csv);
}

#endif //COMPUTERGRAPHIC_DATASET_H
