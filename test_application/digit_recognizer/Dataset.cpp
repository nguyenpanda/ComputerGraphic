//
// Created by Hà Tường Nguyên on 5/29/24.
//

#include "Dataset.h"

namespace AI {

    Dataset::Dataset(std::string csv_path) :
            feature(new std::vector<std::vector<int>*>), target(new std::vector<int>) {
        path = std::move(csv_path);
        std::ifstream mnist(path);
        if (!mnist.is_open()) throw std::invalid_argument("Failed to open file \"" + path + "\"");

        std::string str;

        while (std::getline(mnist, str, '\n')) {
            std::stringstream ss(str);
            std::string temp;
            auto* row = new std::vector<int>;

            std::getline(ss, temp, ',');
            target->push_back(std::stoi(temp));

            while (std::getline(ss, temp, ',')) {
                row->push_back(std::stoi(temp));
            }

            feature->push_back(row);
        }

        mnist.close();
    }

    Dataset::~Dataset() {
        for (auto row_ptr: *feature) {
            delete row_ptr;
        }
        delete feature;
        delete target;
    }

    std::vector<int>& Dataset::operator[](int idx) {
        return *(*feature)[idx];
    }

    void Dataset::print() {
        int i = 0;
        std::cout << target->size() << " - " << feature->size() << std::endl;
        for (const auto& row_ptr: *feature) {
            std::cout << std::setw(3) << (*target)[i++] << " ";
            for (int num: *row_ptr) {
                std::cout << std::setw(3) << num << " ";
            }
            std::cout << std::endl;
        }
    }

    void test_animation(std::string csv) {
        Dataset mnist(std::move(csv));

        graphic::Screen scr(28, 28);

        scr.setUp()->setMapFunc(graphic::MapFunc::two4_bit_map);

        for (int i = 0; i < 199; i++) {
            scr.fill(mnist[i]);
            std::cout << scr;
            std::cout << "\033[28F";
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        std::cout << "\033[0K";
    }
}