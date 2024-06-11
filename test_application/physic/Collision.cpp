//
// Created by ANH KHOA on 6/11/2024.
//

#include "Collision.h"

namespace Physic {

    namespace PhyEnv {
        double mu = 0.1;
        double g = 9.8;
    };

    Particle::Particle(int w, int h) {
        std::mt19937 mt_pos_1(time(nullptr));
        std::uniform_real_distribution<> dist_pos_X(0, w);
        x = dist_pos_X(mt_pos_1);

        std::mt19937 mt_pos_2(time(nullptr));
        std::uniform_real_distribution<> dist_pos_Y(0, h / 3);
        y = dist_pos_Y(mt_pos_2);

        std::mt19937 mt1_vec_1(time(nullptr));
        std::uniform_real_distribution<> dist_vec_1(-60, 60);
        v_x = dist_vec_1(mt1_vec_1);

        std::mt19937 mt1_vec_2(time(nullptr));
        std::uniform_real_distribution<> dist_vec_2(-60, 60);
        v_y = dist_vec_2(mt1_vec_2);

        cal_acc();
    }

    Particle::Particle(double inti_x, double inti_y,
                       double inti_v_x, double inti_v_y,
                       double inti_a_x, double inti_a_y) {
        x = inti_x, y = inti_y;
        v_x = inti_v_x, v_y = inti_v_y;
        a_x = inti_a_x, a_y = inti_a_y;
    }


    void Particle::updateState(double _dt) {
        cal_acc();

        v_x = v_x + a_x * _dt;
        v_y = v_y + a_y * _dt;

        x = x + v_x * _dt;
        y = y + v_y * _dt;
    }

    void Particle::cal_acc() {
        a_x = -PhyEnv::mu * v_x;
        a_y = PhyEnv::g - PhyEnv::mu * v_y;
    }

    int Particle::get_x() const {
        return (int) (v_x < 0 ? floor(x) : ceil(x));
    }

    int Particle::get_y() const {
        return (int) (v_y < 0 ? floor(y) : ceil(y));
    }


    Box::Box(int w, int h, int fps) {
        width = w;
        height = h;
        dt = 1.0 / fps;
        p = new Particle(w, h);
        scr = new graphic::Screen(w, h);
        history = new std::queue<std::pair<int, int> >();
    }

    Box::~Box() {
        delete p;
        delete scr;
        delete history;
    }

    void Box::update_frame() const {
        int x_now = p->get_x();
        int y_now = p->get_y();
        auto point = std::pair<int, int>(x_now, y_now);

        scr->changeAt(255, 255, 255, x_now, y_now);
        history->push(point);

        check_collision();

        p->updateState(dt);
        scr->changeAt(255, 0, 50, p->get_x(), p->get_y());

        std::cout << cursor::preline(width);
        std::cout << scr;

        if (history->size() == 150) {
            auto temp = history->front();
            scr->changeAt(0, 0, 0, temp.first, temp.second);
            history->pop();
        }
    }

    void Box::check_collision() const {
        if (p->x + p->v_x * dt <= 1 || p->x + p->v_x * dt >= width - 1) {
            p->v_x = -p->v_x;
        }

        if (p->y + p->v_y * dt <= 1 || p->y + p->v_y * dt >= height - 1) {
            p->v_y = -p->v_y;
        }
    }

    void gravity() {
        std::cout << "Gravity Falls" << std::endl;
        int w = 120;
        int h = 120;
        int fps = 60;
        Box box(w, h, fps);

        std::cout << cursor::eraseDis(3);

        while (true) {
            try {
                box.update_frame();
            } catch (std::out_of_range& e) {
                cursor::nextline(h);
                std::cout << color::RED << "Object is stopped!!!" << color::RESET << std::endl;
                break;
            }
            std::this_thread::sleep_for(std::chrono::microseconds(10));
        }
    }
}
