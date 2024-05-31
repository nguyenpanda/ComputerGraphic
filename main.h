//
// Created by Hà Tường Nguyên on 5/22/24.
//

#ifndef COMPUTERGRAPHIC_MAIN_H
#define COMPUTERGRAPHIC_MAIN_H

// ComputerGraphic
#include "src/GraphicScreen.h"
#include "src/Utility.h"

// testcase
#include "testcase/testcase.h"

// test_application
#include "test_application/test_application.h"

// custom_test
#include "custom_test.h"

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

namespace cmdline {

    void arg_info() {
        std::cout
                << color::YELLOW << " --h       " << color::RESET << ":            : Help\n"
                << color::YELLOW << " --custom  " << color::RESET << ": <arg1,...> : test_application\n"
                << color::YELLOW << " --ta      " << color::RESET << ": <arg1,...> : test_application\n"
                << color::YELLOW << " --tc      " << color::RESET << ": <arg1,...> : testcase\n"
                << std::endl;
    }

    void help_info() {
        std::cout
                << color::MAGENTA << "--custom" << color::RESET << "\n"
                << color::YELLOW << "\t<no_para>" << color::RESET << "\n"
                //@formatter:off
                << "\t\t-> " << "Define your own testcase in " << color::CYAN << "cmdline::custom_func" << color::RESET << "\n"
                //@formatter:on
                << std::endl;

        std::cout
                << color::MAGENTA << "--ta" << color::RESET << " <application_name>:\n"
                << color::YELLOW << "\t<application_name>" << color::RESET << " parameters:\n"
                //@formatter:off
                << "\t\t-> " << color::CYAN << "-mnist   " << color::RESET << "<file1,...>   " << ": display digits in mnist dataset(s)\n"
                //@formatter:on
                << std::endl;

        std::cout
                << color::MAGENTA << "--tc" << color::RESET << " <testcase>:\n"
                << color::YELLOW << "\t<testcase>" << color::RESET << " parameters:\n"
                //@formatter:off
                << "\t\t-> " << color::CYAN << "all                  " << color::RESET << ": run all testcases below\n"
                << "\t\t-> " << color::CYAN << "circle               " << color::RESET << ": run testcase::all_circle\n"
                << "\t\t-> " << color::CYAN << "line                 " << color::RESET << ": run testcase::all_line\n"
                << "\t\t-> " << color::CYAN << "rectangle            " << color::RESET << ": run testcase::all_rectangle\n"
                << "\t\t-> " << color::CYAN << "change_at            " << color::RESET << ": run testcase::all_change_at\n"
                << "\t\t-> " << color::CYAN << "draw                 " << color::RESET << ": run testcase::all_draw\n"
                << "\t\t-> " << color::CYAN << "operator             " << color::RESET << ": run testcase::all_operator\n"
                << "\t\t-> " << color::CYAN << "plot                 " << color::RESET << ": run testcase::all_plot\n"
                //@formatter:on
                << std::endl;
    }

    void specific_testapp(int& i, int argc, char* argv[]) {
        ++i;
        while (i < argc && (std::string(argv[i]) != "--")) {
            if (std::string(argv[i++]) == "-mnist") {
                if (i < argc) {
                    while (i < argc and argv[i][0] != '-') executeTime(AI::test_animation, std::string(argv[i++]));
                } else
                    std::cout << color::RED << "Error: -mnist option requires an argument." << color::RESET
                              << std::endl;
            }
        }
        --i;
    }

    void specific_testcase(int& i, int argc, char* argv[]) {
        ++i;
        std::string tc_name;
        while (i < argc && argv[i][0] != '-') {
            tc_name = std::string(argv[i]);
            //@formatter:off
            if      (tc_name == "circle")       executeTime(testcase::all_circle);
            else if (tc_name == "line")         executeTime(testcase::all_line);
            else if (tc_name == "rectangle")    executeTime(testcase::all_rectangle);
            else if (tc_name == "change_at")    executeTime(testcase::all_change_at);
            else if (tc_name == "draw")         executeTime(testcase::all_draw);
            else if (tc_name == "operator")     executeTime(testcase::all_operator);
            else if (tc_name == "plot")         executeTime(testcase::all_plot);
            else std::cout << color::RED << "Could not find testcase::" << tc_name << std::endl;
            //@formatter:on
            ++i;
        }
        --i;
    }

}

#endif //COMPUTERGRAPHIC_MAIN_H
