//
// Created by Hà Tường Nguyên on 5/28/24.
//

#include "test_operator.h"

namespace testcase {

    void write_ofstream0() {
        std::cout << color::YELLOW << "testcase::write_ofstream 0" << color::RESET << std::endl;

        graphic::Screen scr(200, 51);

        scr.plot(0, 199, [](int x) -> int {
            return (int) (25 * std::sin(0.2 * (x - 2)));
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;

        std::ofstream file("write_ofstream0.txt");
        file << scr;
        file.close();

    }

    void write_fstream0() {
        std::cout << color::YELLOW << "testcase::write_fstream 1" << color::RESET << std::endl;

        graphic::Screen scr(100, 101);

        scr.plot(0, 99, [](int x) -> int {
            return (int) (50 * std::sin(0.2 * x));
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;

        std::fstream file("write_fstream0.txt", std::ios::out);
        file << scr;
        file.close();

    }

}