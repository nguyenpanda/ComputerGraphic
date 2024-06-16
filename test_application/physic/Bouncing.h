//
// Created by ANH KHOA on 6/11/2024.
//

#ifndef COMPUTERGRAPHIC_BOUNCING_H
#define COMPUTERGRAPHIC_BOUNCING_H

#include "../../src/GraphicScreen.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <random>

namespace Physic {

    class Particle_bouncing;
    class Box_bouncing;

    class Particle_bouncing {
        friend Box_bouncing;

    private:
        double x, y;
        double v_x, v_y;
        double a_x, a_y;

    public:
        Particle_bouncing(int w, int h);

        Particle_bouncing(double inti_x, double inti_y,
                 double inti_v_x, double inti_v_y,
                 double inti_a_x, double inti_a_y);

        ~Particle_bouncing() = default;

        void updateState(double _dt);

        void cal_acc();

        [[nodiscard]] int get_x() const;

        [[nodiscard]] int get_y() const;
    };

    class Box_bouncing {
        friend Particle_bouncing;

    public:
        int width, height;
        double dt;
        Particle_bouncing* p = nullptr;
        graphic::Screen* scr = nullptr;
        std::queue<std::pair<int, int> >* history;

        Box_bouncing(int w, int h, int fps);

        ~Box_bouncing();

        void update_frame() const;

        void check_collision() const;
    };

    void bouncing();
}

#endif //COMPUTERGRAPHIC_BOUNCING_H
