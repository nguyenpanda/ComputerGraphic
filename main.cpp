#include "main.h"

int main(int argc, char* argv[]) {
    std::cout << color::GREEN << "Start program" << color::RESET << std::endl;

    if (argc == 1) {
        cmdline::arg_info();
        std::cout << color::GREEN << "End program" << color::RESET << std::endl;
        return 0;
    }

    std::filesystem::path current_dic = std::filesystem::current_path();
    std::filesystem::create_directory("__output");
    std::filesystem::current_path(current_dic / "__output");
    std::string current_path_exe(argv[0]);

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--h") {
            cmdline::help_info(current_path_exe);
        } else if (std::string(argv[i]) == "--custom") {
            executeTime(cmdline::custom_func);
        } else if (std::string(argv[i]) == "--ta") {
            cmdline::specific_testapp(i, argc, argv);
        } else if (std::string(argv[i]) == "--tc") {
            if (i + 1 < argc) {
                if (std::strcmp(argv[i + 1], "all") == 0) {
                    executeTime(testcase::all);
                    break;
                }

                cmdline::specific_testcase(i, argc, argv);
            } else {
                std::cout << color::RED << "Error: -tc option requires an argument." << color::RESET << std::endl;
                break;
            }
        } else {
            std::cout << color::RED << "Unknown option: " << argv[i] << std::endl;
            break;
        }
    }

    std::cout << color::GREEN << "End program" << color::RESET << std::endl;
    return 0;
}
