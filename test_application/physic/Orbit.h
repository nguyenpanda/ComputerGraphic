//
// Created by Hà Tường Nguyên on 6/17/24.
//

#ifndef COMPUTERGRAPHIC_ORBIT_H
#define COMPUTERGRAPHIC_ORBIT_H

#include "../../src/GraphicScreen.h"

#include <chrono>
#include <limits>
#include <thread>

namespace Physic {

    class Particle_orbit {
    public:
        int width, height;
        double x, y;
        double v_x, v_y;
        double a_x, a_y;

        Particle_orbit(int w, int h);

        void updateState(double _dt);

        void cal_acc();

        [[nodiscard]] int get_x() const;

        [[nodiscard]] int get_y() const;

        double planet_1(double x, double y) const;

        double planet_2(double x, double y) const;
    };

    class Box_orbit {
    public:
        int width, height;
        double dt;
        Particle_orbit* p;
        graphic::Screen* scr;
        std::queue<std::pair<int, int> >* history;

        Box_orbit(int w, int h, int fps);

        ~Box_orbit();

        void update_frame() const;

    };

    void orbit();

}

#endif //COMPUTERGRAPHIC_ORBIT_H
