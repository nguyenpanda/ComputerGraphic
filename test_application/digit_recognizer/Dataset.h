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
        std::vector<std::vector<int>*>* feature;
        std::vector<int>* target;
        std::string path;

    public:

        explicit Dataset(std::string csv_path);

        ~Dataset();

        std::vector<int>& operator[](int idx);

        void print();

    };

    void test_animation(std::string csv);

}

#endif //COMPUTERGRAPHIC_DATASET_H
