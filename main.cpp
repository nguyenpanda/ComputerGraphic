#include "main.h"
#include "sub_code/Dataset.h"

int main(int argc, char* argv[]) {
    std::cout << color::GREEN << "Start program" << color::RESET << std::endl;

    if (argc == 0) {
        testcase::all();
        return 0;
    }

    std::string current_path_exe(argv[0]);

    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                test_animation(argv[++i]);
            } else {
                std::cout << color::RED << "Error: -f option requires an argument." << std::endl;
                return 1;
            }
        } else if (std::strcmp(argv[i], "-t") == 0) {
            testcase::all(); // Will be updated later
        } else {
            std::cout << color::RED << "Unknown option: " << argv[i] << std::endl;
            return 1;
        }
    }

    std::cout << color::GREEN << "End program" << color::RESET << std::endl;
    return 0;
}
