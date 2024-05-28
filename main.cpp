#include "main.h"

int main(int argc, char* argv[]) {
    std::cout << color::GREEN << "Start program" << color::RESET << std::endl;

    testcase::change_at0();
    testcase::change_at1();
    testcase::change_at2(100, 100);

    testcase::draw0();
    testcase::draw1(33, 42, -16, 33);
    testcase::draw2();

    testcase::plot0();
    testcase::plot1(72, 90, -33, 33);
    testcase::plot2();
    testcase::plot3();

    testcase::write_ofstream0();
    testcase::write_fstream0();

    std::cout << color::GREEN << "End program" << color::RESET << std::endl;
    return 0;
}
