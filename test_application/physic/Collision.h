//
// Created by ANH KHOA on 6/11/2024.
//

#ifndef COMPUTERGRAPHIC_COLLISION_H
#define COMPUTERGRAPHIC_COLLISION_H

#include "../../src/GraphicScreen.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <random>
#include <cmath>

namespace Physic {

    class Particle;
    class Box;

    class Particle {
        friend Box;

    private:
        double x, y;
        double v_x, v_y;
        double a_x, a_y;

    public:
        Particle(int w, int h);

        Particle(double inti_x, double inti_y,
                 double inti_v_x, double inti_v_y,
                 double inti_a_x, double inti_a_y);

        ~Particle() = default;

        void updateState(double _dt);

        void cal_acc();

        [[nodiscard]] int get_x() const;

        [[nodiscard]] int get_y() const;
    };

    class Box {
        friend Particle;

    public:
        int width, height;
        double dt;
        Particle* p = nullptr;
        graphic::Screen* scr = nullptr;
        std::queue<std::pair<int, int> >* history;

        Box(int w, int h, int fps);

        ~Box();

        void update_frame() const;

        void check_collision() const;
    };

    void gravity();
}

#endif //COMPUTERGRAPHIC_COLLISION_H
