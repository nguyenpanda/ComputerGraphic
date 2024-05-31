//
// Created by Hà Tường Nguyên on 5/28/24.
//

#include "test_operator.h"

namespace testcase {

    void all_operator() {
        write_ofstream0();
        write_fstream0();
    }

    void write_ofstream0(int w) {
        std::cout << color::YELLOW << "testcase::write_ofstream 0" << color::RESET << std::endl;

        graphic::Screen scr(w, 51);

        scr.plot(0, w - 1, [](int x) -> int {
            return (int) (25 * std::sin(0.2 * (x - 2)));
        });

        std::cout << "------------------" << std::endl;
        std::cout << scr;
        std::cout << "------------------" << std::endl;

        std::ofstream file("write_ofstream0.txt");
        file << scr;
        file.close();

    }

    void write_fstream0(int w) {
        std::cout << color::YELLOW << "testcase::write_fstream 1" << color::RESET << std::endl;

        graphic::Screen scr(w, 101);

        scr.plot(0, w - 1, [](int x) -> int {
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