//
// Created by Hà Tường Nguyên on 5/29/24.
//

#include "testcase.h"

namespace testcase {
    
    void all() {
        change_at0();
        change_at1();
        change_at2(100, 100);

        draw0();
        draw1(33, 42, -16, 33);
        draw2();

        plot0();
        plot1(72, 90, -33, 33);
        plot2();
        plot3();

        write_ofstream0();
        write_fstream0();
    }
    
}
