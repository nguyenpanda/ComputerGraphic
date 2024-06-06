//
// Created by Hà Tường Nguyên on 5/29/24.
//

#include "Dataset.h"

namespace AI {

    Dataset::Dataset(std::string csv_path) :
            feature(new std::vector<std::vector<int>*>), target(new std::vector<int>), errorIdx(new std::vector<int>) {
        path = std::move(csv_path);
        std::ifstream mnist(path);
        if (!mnist.is_open()) throw std::invalid_argument("Failed to open file \"" + path + "\"");

        std::string str;

        int current_index = 0;
        while (std::getline(mnist, str, '\n')) {
            std::stringstream ss(str);
            std::string temp;
            std::getline(ss, temp, ',');
            try {
                target->push_back(std::stoi(temp));
            } catch (std::exception& e) {
                errorIdx->push_back(current_index++);
                continue;
            }

            try {
                auto* row = new std::vector<int>;
                while (std::getline(ss, temp, ',')) {
                    row->push_back(std::stoi(temp));
                }
                feature->push_back(row);
            } catch (std::exception& e) {
                target->pop_back();
                errorIdx->push_back(current_index++);
                continue;
            }

            if (feature->back()->size() != 784) {
                target->pop_back();
                feature->pop_back();
                errorIdx->push_back(current_index);
            }

            ++current_index;
        }

        mnist.close();
    }

    Dataset::~Dataset() {
        for (auto row_ptr: *feature) {
            delete row_ptr;
        }
        delete feature;
        delete target;
        delete errorIdx;
    }

    std::vector<int>& Dataset::operator[](int idx) const {
        return *(*feature)[idx];
    }

    std::vector<int>& Dataset::get_error() const {
        return *errorIdx;
    }

    void Dataset::shape(int& num_of_data, int& num_of_feature) const {
        num_of_feature = (int) feature->size();
        num_of_data = (int) target->size();
    }

    int Dataset::num_error() const {
        return (int) errorIdx->size();
    }

    void Dataset::print() const {
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

    void test_mnist_animation(std::string csv) {
        Dataset mnist(std::move(csv));
        int num_data, num_feature;
        mnist.shape(num_data, num_feature);

        if (mnist.num_error() != 0) {
            std::cout << color::RED << "Number of error line in dataset: " << color::RESET
                      << mnist.num_error()
                      << std::endl;

            std::cout << color::RED << "\t->Error at index: " << color::RESET;
            for (int i = 0; i < mnist.num_error(); ++i) {
                std::cout << mnist.get_error()[i] << ' ';
            }
            std::cout << std::endl;
        }

        graphic::Screen scr(28, 28);

        scr.setUp()->setMapFunc(graphic::MapFunc::two4_bit);
        scr.setUp()->setMapChar(graphic::mapchar::none_char);

        for (int i = 0; i < num_data; i++) {
            scr.fill(mnist[i]);
            std::cout << scr;
            std::cout << cursor::preline(28);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        std::cout << cursor::nextline(28);
    }

    void test_mnist_bitmap(std::string csv) {
        Dataset mnist(std::move(csv));
        int num_data, num_feature;
        mnist.shape(num_data, num_feature);
        std::cout << color::GREEN << "Number of data: " << num_data << color::RESET << std::endl;
        std::cout << color::GREEN << "Number of feature: " << num_feature << color::RESET << std::endl;

        if (mnist.num_error() != 0) {
            std::cout << color::RED << "Number of error line in dataset: " << color::RESET
                      << mnist.num_error()
                      << std::endl;

            std::cout << color::RED << "\t->Error at index: " << color::RESET;
            for (int i = 0; i < mnist.num_error(); ++i) {
                std::cout << mnist.get_error()[i] << ' ';
            }
            std::cout << std::endl;
        }

        std::filesystem::create_directory("bmp_mnist");
        std::filesystem::current_path(std::filesystem::current_path() / "bmp_mnist");

        graphic::Screen scr(28, 28);

        for (int i = 0; i < num_data; i++) {
            scr.fill(mnist[i]);
            graphic::Bitmap(std::to_string(i)) << scr;
        }

        std::filesystem::current_path(std::filesystem::current_path().parent_path());
    }
}